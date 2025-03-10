from functions import *
from bs4 import BeautifulSoup # type: ignore
import requests as req

contentPage = req.get("https://angelgireh.tripod.com/a-b.html").content
soup = BeautifulSoup(contentPage, 'html.parser')

dados = soup.find_all('b')
dadosPP = list()

for d in dados[:10]:
  text = d.get_text(strip=True)
  print(text)
  text = trataTexto(text)

  if text == "":
    continue

  dadosPP.append(text)
  
  """ index_conforme = text.lower().find("conforme")
  if index_conforme != -1:
    text = text[:index_conforme] """    

dadosPP.sort()
print(dadosPP)


