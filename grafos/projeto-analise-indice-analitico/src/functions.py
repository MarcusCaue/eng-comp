def trataTexto(text: str) -> str:
  index_conforme = text.lower().find("conforme")
  if index_conforme != -1:
    text = text[:index_conforme] 

  text = text.strip()

  if text == "":
    return text
  
  if text.isalnum() or text.startswith("-"):
    return ""
  
  if not (text.startswith('A') or text.startswith('B')):
    return ""
  
  return text
  



  
