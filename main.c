#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define MAX_LEN 256
int lengthOfLongestSubstring(char *s)
{
    int maxLen = 0;
    int l = 0;
    int r; // define no repeat char range [l, r]
    if (s == NULL)
    {
        return 0;
    }
    bool record[MAX_LEN];
    memset(record, 0, sizeof(bool) * MAX_LEN);

    int len = strlen(s);
    if (len < 2) {
        return len;
    }
    for (r = 0; r < len; r++)
    {
        if (record[s[r]] == true)
        {
            // 已经存在，右移l到重复字母之后一个，重置重复字母以外滑出窗口的字母
            while (s[r] != s[l])
            {
                record[s[l]] = false;
                l++;
            }
            l++;
        }
        else
        {
            record[s[r]] = true;
        }
        maxLen = maxLen > (r - l + 1) ? maxLen : (r - l + 1);
    }
    return maxLen;
}

int main()
{
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbbbb") == 1);
    assert(lengthOfLongestSubstring("au") == 2);
    return 0;
}
