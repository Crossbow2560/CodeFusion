import playsound
import random
from ifelse import decide
tuple = decide()
def play(tuple):
    l = list(tuple)
    i = random.randint(0, len(l)-1)
    string = f"'{l[i]}'"
    string_form = string[3: len(string) - 4]
    playsound.playsound(string_form)
play(tuple)