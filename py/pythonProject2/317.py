# "ab" is the abbrev of " Address Book"

ab = {
    'Swaroop': 'swaroop@swaroopch.com',
    'Larry': 'larry@wall.org',
    'Matsumoto': 'matz@ruby-lang.org',
    'Spammer': 'spammer@hotmail.com'
}

# print("Swarrop's address is", ab['Swaroop'])

del ab['Spammer']
b = ab.pop('Larry')
print(ab)

print('\nThere are {} contactes in the address-book\n'.format(len(ab)))

for name, address in ab.items():
    print('Contact {} at {}'.format(name, address))

for name in ab.keys():
    print(name)

for address in ab.values():
    print(address)

ab['Guido'] = 'guido@python.org'
#
print(ab.get('Larry'))
#
ab.clear()
#
if 'Guido' in ab:
    print("\nGuido's address is", ab['Guido'])
strp = 'opppoliu'
s = strp[:-3:-1]  # 切片左闭右开
print(s)

if __name__ == '__main__':
    pass
