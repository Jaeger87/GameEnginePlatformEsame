# ![torch](Assets_readme_git/torch.gif) MyUnrealPlatformXDXD ![Green Torch](Assets_readme_git/green_torch.gif)



<p align="center">
<img src="Assets_readme_git/gameplayHLP.gif"  class="center">
</p> <p align="left">



Prototipo di Platform per l'esame di **GameEngine** del [Master di computer game development dell'università di Verona](https://www.mastergamedev.it/) ed ora anche dell'esame di **High Level Programming!**

## Key feature

Porta il micio dalla torcia rossa a quella verde evitando i nemici e di schiantarti a terra (No, non è vero che i gatti se cadono dal quinto piano sopravvivono). Se premi Q muori (anche nella vita reale? Scoprilo premendo Q!!!). Ci sono 4 item che puoi raccogliere a terra e che possono cambiare le statistiche del tuo eroe!

Elemento | Descrizione
------------ | -------------
![Micio](Assets_readme_git/micio.gif) | Personaggio controllabile dal giocatore, può saltare e muoversi, se casca da un punto troppo alto muore ::sob::
![Nemico](Assets_readme_git/enemy.gif) | Nemico nel gioco, ha lo stesso comportamento dei Goomba di Super Mario, perciò uccide il giocatore se lo tocca, se sbatte su qualcosa cambia direzione e non ha paura di buttarsi in un dirupo. Può essere ucciso saltandogli in testa.
<img src="Assets_readme_git/rockTile.png" alt="rock" width="80"/>| Tile classica su cui possono muoversi i personaggi
<img src="Assets_readme_git/grass_tile.png" alt="grass" width="80"/>| Weak tile, calpestabile ma attraversabile dal basso verso l'alto
<img src="Assets_readme_git/Magic_Tile.png" alt="Magic" width="80"/>| Tile che si muove da un punto all'altro nel livello
<img src="Assets_readme_git/torch.gif" alt="Magic" width="40" class="center"/>| Punto di partenza e di respawn del livello
<img src="Assets_readme_git/green_torch.gif" alt="Magic" width="40" class="center"/>| Punto di arrivo
<img src="Assets_readme_git/FeetOutline 12.png" alt="grass" width="64" class="center"/>| Scarponi leggeri, se il giocatore li raccoglie diventa più veloce
<img src="Assets_readme_git/MiscellaneousOutline 36.png" alt="Magic" width="64" class="center"/>| Formaggio magico, rende invincibili per 5 secondi, quando il giocatore è invincibile non può morire in alcun modo e uccide i nemici toccandoli (simile a Super Mario con la stella).
<img src="Assets_readme_git/RingOutline 13.png" alt="Magic" width="64" class="center"/>| Anello piuma, Se raccolto aumenta l'attrito dell'aria durante le cadute del giocatore e lo fa sempre cadere con leggere, come se avesse un paracadute.
<img src="Assets_readme_git/HelmetOutline 2.png" alt="Magic" width="64"/>| Aumenta velocità e attrito dell'aria, inserita solo a scopo dimostrativo.


# Micio stats

Nome | Descrizione | Valore Default
------------ | ------------- | -------------
Speed | Moltiplicatore in grado di alterare la velocità del micio, maggiore di 1 rende il micio più veloce, minore di 1 lo rende più lento | 1
InvincibleSeconds | Durata residua in secondi del potere dell'invincibilità, questo valore decresce col tempo fino ad arrivare a 0. | 0
AirFriction | Un moltiplicatore che se abbassato rende le caduta dopo un salto più lente | 1



# Notion e Unreal :heartpulse:



I 4 Item del gioco interagiscono con 3 diversi tipi di statistica del personaggio principale. Su [Notion](https://www.notion.so/) è stato creato un [DataBase delle item](https://decisive-nutmeg-629.notion.site/Design-stuff-836432e292e249c4801db0d20134afc3) (a cui chiunque può accedere in lettura) dove si può trovare:

* Nome dell'Item
* Descrizione ad alto livello di cosa fa l'Item
* Asset grafico che rappresenta l'item
* Valori delle statistiche alterate dall'item.


<p align="center">
<img src="Assets_readme_git/PaginaNotion.png"  class="center">
</p> <p align="left">

Tramite lo script Python [NotiontoUnreal.py](https://github.com/Jaeger87/GameEnginePlatformEsame/blob/HLP/NotionToUnreal.py) è possibile in automatico importare i valori delle stats modificate da ogni item. Lo script legge i valori nel DB Notion e crea i CSV che Unreal legge per creare le DataTable relative. Fatta questa opzione bisognerà fare un refresh delle DataTable da Unreal. 

https://user-images.githubusercontent.com/8321575/164917049-c5b84396-8949-466a-8221-521a784d35e6.mp4


In caso di aggiunta, rimozione o cambia nome di una stat, **non ci sarà bisogno** di toccare NotiontoUnreal.py perché questo si limita soltanto a leggere quello che trova nella tabella e riportarlo nei CSV.

# Assets source

Asset | Source
------------ | -------------
Scheletro | https://astrobob.itch.io/animated-pixel-art-skeleton
Background | https://ansimuz.itch.io/mountain-dusk-parallax-background
Gatto | https://9e0.itch.io/cute-legends-cat-heroes
Tiles | https://shackhal.itch.io/multi-platformer-tileset
Torce | https://aamatniekss.itch.io/deep-forest-pixel-tileset
Items | https://iknowkingrabbit.itch.io/heroic-icon-pack

