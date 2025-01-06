import sqlite3
bpm = int(input("enter the Bpm recorded :"))
print(bpm)
con = sqlite3.connect('database.db')
c = con.cursor()

def decide():
    if bpm <= int(85):
        c.execute("select song_path  from database where initial_bpm = 95")
        list = c.fetchall()
    elif bpm <= int(95):
        c.execute("select song_path  from database where initial_bpm = 85")
        list = c.fetchall()
    elif bpm <= int(110):
        c.execute("select song_path from database where initial_bpm = 70")
        list = c.fetchall()

    return list