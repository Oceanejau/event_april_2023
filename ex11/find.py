import requests

print("Enter the name of a Pokemon: ", end="")
name = input().lower()
link = f"https://pokeapi.co/api/v2/pokemon/{name}"
response = requests.get(link)
if response.status_code == 404:
    print("Error: Pokemon not found.")
else:
    data = response.json()
    data['name'] = data["name"].capitalize()
    print("Name:", data['name'])
    print("Abilities:")
    for ability in data['abilities']:
        print("-", ability['ability']['name'].capitalize())
