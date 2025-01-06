import sqlite3
from Data import song_name_list, initial_bpm_list, final_bpm_list, song_link_list, song_path_list

con = sqlite3.connect('database.db')
c = con.cursor()

c.execute("create table database(song_name varchar(20), initial_bpm int(10), final_bpm int(10), song_link varchar(200), song_path varchar(200))")

def EntryAdd(song_name, initial_bpm, final_bpm, song_link, song_path):
    c.execute("insert into database values(?, ?, ?, ?, ?)",(song_name, initial_bpm, final_bpm, song_link, song_path))
    con.commit()

for i in range(0, 18):
    EntryAdd(song_name_list[i], initial_bpm_list[i], final_bpm_list[i], song_link_list[i], song_path_list[i])

