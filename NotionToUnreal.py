import json
import requests
import csv


with open('NotionSecrets.txt', 'r') as notionFile:
  token = notionFile.readline()[:-1]
  database_id = notionFile.readline()[:-1]


csvPath = 'MyUnrealPlatformXDXD/Content/ItemsDataTables/'



def mapNotionResultToItem(result):
  # you can print result here and check the format of the answer.
  properties = result['properties']
  itemName = properties['Name']['title'][0]['text']['content']
  with open(csvPath + itemName + '.csv', 'w', newline='', encoding='UTF8') as f:
    writer = csv.writer(f, lineterminator='\n')
    writer.writerow(['RowName' ,'Stat Name', 'Value']) 
    rowNameCounter = 0
    for propertyKey in properties.keys():
      if propertyKey == 'Name':
        continue
      currentProperty = properties[propertyKey]
      propertyType = currentProperty['type']
      propertyValue = currentProperty[propertyType]
      if(propertyValue != None):
        writer.writerow(['RowName_' + str(rowNameCounter),propertyKey, propertyValue]) 
      rowNameCounter +=1




def getItems():
  url = f'https://api.notion.com/v1/databases/{database_id}/query'

  r = requests.post(url, headers={
    "Authorization": f"Bearer {token}",
    "Notion-Version": "2021-08-16"
  })

  result_dict = r.json()
  items_list_result = result_dict['results']

  for item in items_list_result:
  	mapNotionResultToItem(item)

  print(items_list_result)


getItems()