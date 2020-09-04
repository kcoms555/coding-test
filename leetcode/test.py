def isValid(s: str) -> bool:
	l = []
	open = ['(', '[', '{']
	close = [')', ']', '}']
	for c in s:
		print(c);
		if c in open:
			l.append(c)
		if c in close:
			if not l:
				return False
			if open.index(l.pop()) != close.index(c):
				return False
	return not l
print(isValid("([])"))
print(isValid("([)]"))
print(isValid(")([)]("))
