#include <stdlib.h>
#include <string.h>

typedef struct
{
    int p2;
    int p3;
    int p5;
    int p7;
} Factors;

/*
    Prime factors of digits 0..9

    digit  2 3 4 5 6 7 8 9
    ------------------------
    2      1 0 2 0 1 0 3 0
    3      0 1 0 0 1 0 0 2
    5      0 0 0 1 0 0 0 0
    7      0 0 0 0 0 1 0 0
*/
static const Factors digitFactor[10] =
{
    {0, 0, 0, 0},   // 0
    {0, 0, 0, 0},   // 1
    {1, 0, 0, 0},   // 2
    {0, 1, 0, 0},   // 3
    {2, 0, 0, 0},   // 4
    {0, 0, 1, 0},   // 5
    {1, 1, 0, 0},   // 6
    {0, 0, 0, 1},   // 7
    {3, 0, 0, 0},   // 8
    {0, 2, 0, 0}    // 9
};

/*
    Convert prime requirements into actual digits.

    Example:

    2^8
       -> 8,8

    2^6 * 3
       -> 6,8

    3^2
       -> 9
*/
static Factors makeDigits(Factors f)
{
    Factors result = {0, 0, 0, 0};

    int count8 = f.p2 / 3;
    int remaining2 = f.p2 % 3;

    int count9 = f.p3 / 2;
    int remaining3 = f.p3 % 2;

    int count4 = remaining2 / 2;
    int count2 = remaining2 % 2;

    int count6 = 0;

    /*
        Combine 2 and 3 -> 6
    */
    if (count2 == 1 && remaining3 == 1)
    {
        count2 = 0;
        remaining3 = 0;
        count6 = 1;
    }

    /*
        Combine 4 and 3 -> 6 + 2

        4 * 3 = 12
        6 * 2 = 12
    */
    if (remaining3 == 1 && count4 == 1)
    {
        count4 = 0;
        remaining3 = 0;

        count2 = 1;
        count6 = 1;
    }

    result.p2 = count2;
    result.p3 = remaining3;
    result.p5 = f.p5;
    result.p7 = f.p7;

    /*
        We temporarily use these fields differently:
        p2 -> count of digit 2
        p3 -> count of digit 3
        p5 -> count of digit 5
        p7 -> count of digit 7

        The other digits are returned through a separate
        encoding below, so this helper isn't used directly.
    */

    return result;
}

/*
    Get how many actual digits are needed.

    digits[2] = number of 2s
    digits[3] = number of 3s
    ...
*/
static void getDigitCounts(Factors f, int digits[10])
{
    for (int i = 0; i < 10; i++)
        digits[i] = 0;

    /*
        Use as many 8s as possible.
    */
    digits[8] = f.p2 / 3;
    f.p2 %= 3;

    /*
        Use as many 9s as possible.
    */
    digits[9] = f.p3 / 2;
    f.p3 %= 2;

    /*
        Remaining 2s.
    */
    digits[4] = f.p2 / 2;
    f.p2 %= 2;

    /*
        Remaining 3 and 2 -> 6
    */
    if (f.p2 == 1 && f.p3 == 1)
    {
        digits[6]++;
        f.p2 = 0;
        f.p3 = 0;
    }

    /*
        Remaining 3 + 4 can be represented by 6 + 2.
    */
    if (f.p3 == 1 && digits[4] > 0)
    {
        digits[4]--;
        digits[6]++;
        digits[2]++;

        f.p3 = 0;
    }

    digits[2] += f.p2;
    digits[3] += f.p3;
    digits[5] = f.p5;
    digits[7] = f.p7;
}

/*
    Number of digits required to represent the factors.
*/
static int requiredLength(Factors f)
{
    int digits[10];

    getDigitCounts(f, digits);

    int total = 0;

    for (int i = 2; i <= 9; i++)
        total += digits[i];

    return total;
}

/*
    Build the smallest number having the required
    digit product.

    Digits are placed in ascending order.

    Example:
        factors of 256 = 2^8

        2^8 -> 8 * 8

        result = "88"
*/
static char* buildNumber(Factors f)
{
    int digits[10];

    getDigitCounts(f, digits);

    int len = 0;

    for (int i = 2; i <= 9; i++)
        len += digits[i];

    char *result = malloc(len + 1);

    int k = 0;

    for (int d = 2; d <= 9; d++)
    {
        for (int j = 0; j < digits[d]; j++)
        {
            result[k++] = '0' + d;
        }
    }

    result[k] = '\0';

    return result;
}

/*
    Check whether prefix already contains enough
    prime factors for t.
*/
static int satisfies(Factors need, Factors have)
{
    return have.p2 >= need.p2 &&
           have.p3 >= need.p3 &&
           have.p5 >= need.p5 &&
           have.p7 >= need.p7;
}

/*
    Calculate remaining factors after using
    prefix + one digit.
*/
static Factors getRemaining(Factors need,
                            Factors prefix,
                            int digit)
{
    Factors result;

    result.p2 = need.p2 - prefix.p2 - digitFactor[digit].p2;
    result.p3 = need.p3 - prefix.p3 - digitFactor[digit].p3;
    result.p5 = need.p5 - prefix.p5 - digitFactor[digit].p5;
    result.p7 = need.p7 - prefix.p7 - digitFactor[digit].p7;

    if (result.p2 < 0)
        result.p2 = 0;

    if (result.p3 < 0)
        result.p3 = 0;

    if (result.p5 < 0)
        result.p5 = 0;

    if (result.p7 < 0)
        result.p7 = 0;

    return result;
}

/*
    LeetCode 3348
*/
char* smallestNumber(char* num, long long t)
{
    int n = strlen(num);

    /*
        Step 1:
        Factor t into 2, 3, 5 and 7.
    */
    Factors need = {0, 0, 0, 0};

    while (t % 2 == 0)
    {
        need.p2++;
        t /= 2;
    }

    while (t % 3 == 0)
    {
        need.p3++;
        t /= 3;
    }

    while (t % 5 == 0)
    {
        need.p5++;
        t /= 5;
    }

    while (t % 7 == 0)
    {
        need.p7++;
        t /= 7;
    }

    /*
        If something remains, it contains a prime
        factor other than 2,3,5,7.

        No digit 1..9 can provide that factor.
    */
    if (t != 1)
    {
        char *ans = malloc(3);

        ans[0] = '-';
        ans[1] = '1';
        ans[2] = '\0';

        return ans;
    }

    /*
        Step 2:
        If t requires more digits than num has,
        construct the shortest possible answer.
    */
    if (requiredLength(need) > n)
    {
        return buildNumber(need);
    }

    /*
        Step 3:
        Count prime factors in the whole num.
    */
    Factors prefix = {0, 0, 0, 0};

    int firstZero = n;

    for (int i = 0; i < n; i++)
    {
        int d = num[i] - '0';

        if (d == 0 && firstZero == n)
        {
            firstZero = i;
        }

        prefix.p2 += digitFactor[d].p2;
        prefix.p3 += digitFactor[d].p3;
        prefix.p5 += digitFactor[d].p5;
        prefix.p7 += digitFactor[d].p7;
    }

    /*
        Step 4:
        If num is zero-free and already satisfies t,
        return num.
    */
    if (firstZero == n && satisfies(need, prefix))
    {
        char *ans = malloc(n + 1);

        strcpy(ans, num);

        return ans;
    }

    /*
        We now search from right to left.

        We want to change the rightmost possible digit
        while keeping the prefix equal to num.

        Example:

            1234
               ^
            try 5,6,7,8,9

        If impossible:

            1234
              ^
            try changing 3 -> 4,5,...
    */

    for (int i = n - 1; i >= 0; i--)
    {
        int currentDigit = num[i] - '0';

        /*
            Remove current digit from prefix.

            After this:
            prefix = factors of num[0 ... i-1]
        */
        prefix.p2 -= digitFactor[currentDigit].p2;
        prefix.p3 -= digitFactor[currentDigit].p3;
        prefix.p5 -= digitFactor[currentDigit].p5;
        prefix.p7 -= digitFactor[currentDigit].p7;

        /*
            If there is a zero before this position,
            the unchanged prefix would contain zero.
            Therefore this pivot is impossible.
        */
        if (i > firstZero)
            continue;

        /*
            Try the smallest possible larger digit.
        */
        int start = currentDigit + 1;

        if (start < 1)
            start = 1;

        for (int d = start; d <= 9; d++)
        {
            /*
                Find factors still required after:

                prefix + new digit
            */
            Factors remaining =
                getRemaining(need, prefix, d);

            int suffixLength =
                n - i - 1;

            /*
                Can the remaining factors fit
                inside the suffix?
            */
            if (requiredLength(remaining) <= suffixLength)
            {
                /*
                    Build:

                    prefix
                    +
                    changed digit
                    +
                    some 1s
                    +
                    required digits
                */

                char *suffix =
                    buildNumber(remaining);

                int required =
                    strlen(suffix);

                int ones =
                    suffixLength - required;

                char *ans =
                    malloc(n + 1);

                int k = 0;

                /*
                    Copy prefix.
                */
                for (int j = 0; j < i; j++)
                {
                    ans[k++] = num[j];
                }

                /*
                    Changed digit.
                */
                ans[k++] = '0' + d;

                /*
                    Put 1s first.
                    This gives the smallest suffix.
                */
                for (int j = 0; j < ones; j++)
                {
                    ans[k++] = '1';
                }

                /*
                    Add required digits.
                */
                for (int j = 0; j < required; j++)
                {
                    ans[k++] = suffix[j];
                }

                ans[k] = '\0';

                free(suffix);

                return ans;
            }
        }
    }

    /*
        Step 5:
        No number of the same length works.

        Therefore construct the smallest number
        with n + 1 digits.

        Example:

        9999

        -> 111...
    */

    Factors remaining = need;

    char *suffix = buildNumber(remaining);

    int suffixLength = strlen(suffix);

    int totalLength = n + 1;

    char *ans = malloc(totalLength + 1);

    int ones = totalLength - suffixLength;

    int k = 0;

    for (int i = 0; i < ones; i++)
    {
        ans[k++] = '1';
    }

    for (int i = 0; i < suffixLength; i++)
    {
        ans[k++] = suffix[i];
    }

    ans[k] = '\0';

    free(suffix);

    return ans;
}