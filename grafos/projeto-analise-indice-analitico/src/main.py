from bs4 import BeautifulSoup
import requests as req

contentPage = req.get("https://angelgireh.tripod.com/a-b.html").content
soup = BeautifulSoup(contentPage, 'html.parser')

topicos = soup.find_all('span', style="mso-bidi-font-size:9.0pt")

print(topicos)
