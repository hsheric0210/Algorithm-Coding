def solution(s, skip, index):
    table = ''
    for i in range(ord('A'), ord('Z')+1):
        if chr(i) not in skip:
            table += chr(i)
    lookup = dict()
    for ch in table:
        lookup[ch] = (ord(ch) + index - ord('A')) % len(table) + ord('A')
    answer = ''
    for ch in s:
        answer += lookup[ch]
    return answer

print(solution("aukks",	"wbqd",	5))
