
def romanToInt(s):
    """
    :type s: str
    :rtype: int
    """


    number = 0
    
    values = [  ('I', 1),
                ('V', 5),
                ('X', 10),
                ('L', 50),
                ('C', 100),
                ('D', 500),
                ('M', 1000) ]
    d_values = dict(values)
    order = "IVXLCDM"

    index = 0
    while index < len(s):
        if index == len(s)-1 or order.find(s[index]) >= order.find(s[index+1]):
            number += d_values[s[index]]
        else:
            if ((s[index] == "I" and (s[index+1] == "V" or s[index+1] == "X")) or
                (s[index] == "X" and (s[index+1] == "L" or s[index+1] == "C")) or
                (s[index] == "C" and (s[index+1] == "D" or s[index+1] == "M"))):
                number += d_values[s[index+1]] - d_values[s[index]]
                index += 1
  
        index += 1

    return number
