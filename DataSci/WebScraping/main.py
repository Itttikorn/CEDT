from bs4 import BeautifulSoup

def Q1(file_path):  # DO NOT modify this line
    with open(file_path, encoding='utf-8') as f:
        html = f.read()
    soup = BeautifulSoup(html, 'lxml')
    bud_day_count = [0, 0, 0, 0, 0, 0, 0]
    for day in soup.find_all('div', attrs={'class': 'bud-day-col'}):
        inner_html = day.decode_contents()
        if 'วันจันทร์' in inner_html:
            bud_day_count[0] += 1
        elif 'วันอังคาร' in inner_html:
            bud_day_count[1] += 1
        elif 'วันพุธ' in inner_html:
            bud_day_count[2] += 1
        elif 'วันพฤหัสบดี' in inner_html:
            bud_day_count[3] += 1
        elif 'วันศุกร์' in inner_html:
            bud_day_count[4] += 1
        elif 'วันเสาร์' in inner_html:
            bud_day_count[5] += 1
        elif 'วันอาทิตย์' in inner_html:
            bud_day_count[6] += 1
    return bud_day_count

def Q2(file_path):  # DO NOT modify this line
    with open(file_path, encoding='utf-8') as f:
        html = f.read()
    soup = BeautifulSoup(html, 'lxml')
    for day in soup.find_all('div', attrs={'class': 'bud-day'}):
        date = ''
        for col in day.find_all('div', attrs={'class': 'bud-day-col'}):
            if 'ที่' in col.decode_contents():
                date = col.decode_contents()
            for a in col.find_all('a'):
                inner_html = a.decode_contents()
                if 'วันวิสาขบูชา' in inner_html:
                    return date
    return

exec(input().strip())  # do not delete this line