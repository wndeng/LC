import json
import math
import cProfile

# def Manacher(s): # Purely to understand the concept, no optimizations and does not simplify the answer
#     if s == "":
#         return ""
#     p = [-1 for _ in s]
#     p[0] = 0
#     p[1] = 1
#     center = 1
#     L = 0
#     R = 2
#     current = 2
#     best = (0,0)

#     while current <= len(s)-1:
#         if(current == R):
#             i = 1
#             center = current
#             while(center - i >= 0 and center + i < len(s) and s[center - i] == s[center + i]):
#                 i+= 1
#             p[center] = i - 1
#             if(p[center] > best[0]):
#                 best = (center, p[center])
#             current = center + 1

#         elif p[2*center - current] < R - current:
#             p[current] = p[2*center - current]
#             if(p[current] > best[1]):
#                 best = (current, p[current])
#             current += 1

#         elif p[2*center - current] == R - current:
#             if R == len(s)-1:
#                 p[current] = p[2*center - current]
#                 if(p[current] > best[1]):
#                     best = (current, p[current])
#                 current += 1

#             else:
#                 i = p[2*center - current] + 1
#                 center = current
#                 while(center - i >= 0 and center + i < len(s) and s[center - i] == s[center + i]):
#                     i+= 1

#                 p[center] = i - 1
#                 if(p[center] > best[1]):
#                     best = (center, p[center])
#                 L = center - p[center]
#                 R = center + p[center]
#                 current = center + 1

#         elif p[2*center - current] > R - current:
#             i = R - current + 1
#             center = current
#             while(center - i >= 0 and center + i < len(s) and s[center - i] == s[center + i]):
#                 i+= 1
#             p[center] = i - 1
#             if(p[center] > best[1]):
#                 best = (center, p[center])
#             L = center - p[center]
#             R = center + p[center]
#             current = center + 1

#     print(p)
#     print(best)
#     return s[best[0] - best[1]:best[0]+best[1] + 1]

# def checker(s): # Reference Program
#     p = []
#     for i in range(len(s)):
#         f = 1;
#         while(i - f >= 0 and i + f < len(s) and s[i - f] == s[i + f]):
#             f += 1

#         p.append(f - 1)
#     print(p)


# ___________________________Optimized Solution ________________________


class ezStr(str): # Index virtualization
    def __init__(self, str):
        self.str = str
    def __getitem__(self, key):
        if(key % 2 == 1):
            return self.str[(key-1)//2]
        else:
            return '#'


def longestPalindrome(s):
    if(len(s) == 1 or len(s) == 0):
        return s;

    s2 = s
    s = ezStr(s)
    size = 2*len(s)+1;

    max_ind = size - 1;
    p = [-1 for _ in range(size)]

    p[0] = 0
    current_center = 0
    max_left_ind = 0
    max_right_ind = 0
    current_ind = 1
    radius = 0
    best = (1, 1) # radius, index location

    while(best[0] <= max_ind - current_ind):
        left = current_ind # Left iterator
        right = current_ind # right iterator
        radius = 0

        if(current_ind + 2 < max_ind and current_ind % 2 == 1 and s[current_ind + 2] == s[current_ind]): # Actual char, update current center and radius to skip repetition
            print('a')
            while(right + 2 <=  max_ind and s[right] == s[right+2]):
                right += 2

            radius = (right - left)//2
            current_ind = right + 2
            current_center = left + radius # Middle must be the greatest possible palindrome

            while(0 < left <= right < max_ind and s[left - 1] == s[right + 1]): # Do further comparison to find max radius
                left -= 1
                right += 1
                radius += 1

            p[current_center] = radius
            max_left_ind = current_ind
            max_right_ind = current_ind

            if radius > best[0]:
                best = (radius, current_center)
            continue

        if(current_ind < max_right_ind and p[2*current_center - current_ind] >= max_right_ind - current_ind):
            print('b')
            radius = max_right_ind - current_ind
            left -= radius;
            right += radius;

        elif(current_ind < max_right_ind and p[2*current_center - current_ind] < max_right_ind - current_ind): # subpalindrome within current palindrome, no need to expand. Go to next index
            print('c')
            p[current_ind] = max(0, p[2*current_center - current_ind])

            if radius > best[0]:
                best = (radius, current_ind)

            if(p[current_ind] != 0):
                current_ind += 1
                continue

        while(0 < left <= right < max_ind and s[left - 1] == s[right + 1]): # Do further comparison to find max radius
            left -= 1
            right += 1
            radius += 1

        p[current_ind] = radius
        current_center = current_ind
        max_left_ind = left
        max_right_ind = right

        if radius > best[0]:
            best = (radius, current_ind)

        current_ind += 1

    s2 = ""
    print(p)
    print(best)
    for i in range(best[1] + 1 - best[0], best[1] + 1 + best[0], 2):
        s2 += s[i]

    return s2



def longestPalindromeNormal(s):
    """
    :type s: str
    :rtype: str
    """
    
    if s == s[::-1] or not s:
        return s
    

    start = 0
    length = 1

    for i in range(2, len(s) + 2 -  length):
        if i -  length - 1 >= 1:
            if s[i -  length - 2:i] == s[i -  length - 2:i][::-1]:
                start = i - length - 2
                length += 2
                continue
        if i - length - 1 >= 0:
            if s[i -  length - 1:i] == s[i -  length - 1:i][::-1]:
                start = i -  length - 1
                length += 1
    
    return s[start:start + length]

def main():
    # t = "#b#b#"
    # Manacher(t)
    # checker(t)
    # longestPalindrome("aabaa")
    print(longestPalindromeNormal("cbbd"))

if __name__ == '__main__':
    main()