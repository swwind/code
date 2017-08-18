#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[1001] = {0LL, 1LL, 2LL, 3LL, 4LL, 6LL, 6LL, 9LL, 11LL, 14LL, 16LL, 20LL, 23LL, 27LL, 31LL, 35LL, 43LL, 47LL, 55LL, 61LL, 70LL, 78LL, 88LL, 98LL, 111LL, 123LL, 136LL, 152LL, 168LL, 187LL, 204LL, 225LL, 248LL, 271LL, 296LL, 325LL, 356LL, 387LL, 418LL, 455LL, 495LL, 537LL, 581LL, 629LL, 678LL, 732LL, 787LL, 851LL, 918LL, 986LL, 1056LL, 1133LL, 1217LL, 1307LL, 1399LL, 1498LL, 1600LL, 1708LL, 1823LL, 1950LL, 2083LL, 2218LL, 2356LL, 2506LL, 2671LL, 2842LL, 3025LL, 3211LL, 3409LL, 3610LL, 3830LL, 4067LL, 4316LL, 4568LL, 4829LL, 5105LL, 5406LL, 5722LL, 6051LL, 6393LL, 6746LL, 7112LL, 7506LL, 7928LL, 8372LL, 8821LL, 9282LL, 9770LL, 10293LL, 10845LL, 11423LL, 12013LL, 12621LL, 13255LL, 13930LL, 14653LL, 15410LL, 16176LL, 16960LL, 17785LL, 18663LL, 19591LL, 20553LL, 21545LL, 22560LL, 23616LL, 24734LL, 25933LL, 27174LL, 28439LL, 29728LL, 31076LL, 32509LL, 34026LL, 35595LL, 37204LL, 38850LL, 40557LL, 42366LL, 44282LL, 46270LL, 48301LL, 50360LL, 52517LL, 54796LL, 57199LL, 59689LL, 62243LL, 64838LL, 67535LL, 70375LL, 73378LL, 76499LL, 79669LL, 82896LL, 86259LL, 89808LL, 93544LL, 97408LL, 101346LL, 105371LL, 109528LL, 113898LL, 118515LL, 123298LL, 128161LL, 133123LL, 138260LL, 143662LL, 149346LL, 155217LL, 161203LL, 167304LL, 173602LL, 180223LL, 187188LL, 194394LL, 201727LL, 209179LL, 216887LL, 225004LL, 233478LL, 242246LL, 251189LL, 260296LL, 269680LL, 279534LL, 289857LL, 300546LL, 311405LL, 322443LL, 333839LL, 345784LL, 358285LL, 371203LL, 384343LL, 397730LL, 411531LL, 425953LL, 441059LL, 456667LL, 472506LL, 488623LL, 505255LL, 522633LL, 540796LL, 559541LL, 578622LL, 598040LL, 618004LL, 638849LL, 660655LL, 683132LL, 706001LL, 729237LL, 753154LL, 778157LL, 804249LL, 831083LL, 858442LL, 886231LL, 914803LL, 944588LL, 975676LL, 1007714LL, 1040309LL, 1073406LL, 1107489LL, 1142976LL, 1179941LL, 1218033LL, 1256772LL, 1296102LL, 1336565LL, 1378646LL, 1422511LL, 1467723LL, 1513662LL, 1560288LL, 1608264LL, 1658153LL, 1710050LL, 1763441LL, 1817764LL, 1872970LL, 1929640LL, 1988528LL, 2049843LL, 2112903LL, 2177002LL, 2242117LL, 2308930LL, 2378345LL, 2450550LL, 2524753LL, 2600227LL, 2676925LL, 2755570LL, 2837222LL, 2922075LL, 3009300LL, 3097939LL, 3187910LL, 3280268LL, 3376122LL, 3475560LL, 3577799LL, 3681810LL, 3787349LL, 3895580LL, 4007781LL, 4124158LL, 4243812LL, 4365410LL, 4488795LL, 4615345LL, 4746534LL, 4882547LL, 5022247LL, 5164208LL, 5308385LL, 5456077LL, 5608963LL, 5767544LL, 5930385LL, 6095779LL, 6263781LL, 6435911LL, 6613993LL, 6798505LL, 6987901LL, 7180330LL, 7375721LL, 7575773LL, 7782710LL, 7997065LL, 8217094LL, 8440659LL, 8667488LL, 8899739LL, 9140016LL, 9388512LL, 9643384LL, 9902531LL, 10165513LL, 10434616LL, 10712858LL, 11000633LL, 11295797LL, 11595731LL, 11900036LL, 12211421LL, 12533095LL, 12865645LL, 13206691LL, 13553187LL, 13904850LL, 14264665LL, 14636001LL, 15019870LL, 15413510LL, 15813151LL, 16218675LL, 16633663LL, 17061853LL, 17504131LL, 17957511LL, 18418083LL, 18885444LL, 19363284LL, 19856106LL, 20365018LL, 20886445LL, 21416170LL, 21953633LL, 22502996LL, 23069688LL, 23654627LL, 24253578LL, 24862140LL, 25479632LL, 26110444LL, 26760714LL, 27431758LL, 28118910LL, 28816859LL, 29524995LL, 30248724LL, 30994342LL, 31763154LL, 32550426LL, 33350018LL, 34161082LL, 34989834LL, 35843243LL, 36722969LL, 37623961LL, 38538864LL, 39466642LL, 40414595LL, 41390540LL, 42395999LL, 43425108LL, 44470326LL, 45530615LL, 46613390LL, 47727748LL, 48875865LL, 50050571LL, 51243342LL, 52453405LL, 53688691LL, 54959424LL, 56268254LL, 57607048LL, 58966572LL, 60345981LL, 61753831LL, 63201526LL, 64692137LL, 66216763LL, 67764588LL, 69334382LL, 70936798LL, 72584395LL, 74279577LL, 76013285LL, 77773910LL, 79559305LL, 81381225LL, 83253875LL, 85179845LL, 87149249LL, 89149075LL, 91176899LL, 93245998LL, 95372229LL, 97558561LL, 99793501LL, 102062615LL, 104363895LL, 106711118LL, 109121778LL, 111600554LL, 114134202LL, 116705815LL, 119314243LL, 121974988LL, 124706573LL, 127514054LL, 130383070LL, 133295058LL, 136248424LL, 139260259LL, 142351499LL, 145527797LL, 148773538LL, 152068169LL, 155408850LL, 158815052LL, 162310911LL, 165901151LL, 169568417LL, 173291577LL, 177066812LL, 180915029LL, 184863771LL, 188918534LL, 193059430LL, 197262777LL, 201524816LL, 205868795LL, 210324461LL, 214898330LL, 219569114LL, 224310043LL, 229117452LL, 234017083LL, 239040338LL, 244195775LL, 249460339LL, 254802436LL, 260218466LL, 265738585LL, 271396945LL, 277202139LL, 283129321LL, 289144535LL, 295242993LL, 301456932LL, 307824977LL, 314356624LL, 321023550LL, 327789549LL, 334649288LL, 341637377LL, 348797935LL, 356141163LL, 363634328LL, 371238934LL, 378949177LL, 386801433LL, 394844883LL, 403092443LL, 411507682LL, 420046804LL, 428704287LL, 437521813LL, 446551722LL, 455807005LL, 465249543LL, 474830686LL, 484543355LL, 494434944LL, 504562393LL, 514939726LL, 525527157LL, 536269941LL, 547158658LL, 558246803LL, 569597371LL, 581224252LL, 593083626LL, 605117138LL, 617314792LL, 629733181LL, 642443002LL, 655461536LL, 668737718LL, 682206885LL, 695860533LL, 709759227LL, 723979796LL, 738543076LL, 753392290LL, 768456802LL, 783728737LL, 799272915LL, 815172700LL, 831452246LL, 848050243LL, 864887178LL, 881953128LL, 899322732LL, 917087901LL, 935271624LL, 953809031LL, 972615020LL, 991675037LL, 1011070969LL, 1030905654LL, 1051202104LL, 1071889555LL, 1092876582LL, 1114146494LL, 1135789191LL, 1157918165LL, 1180558496LL, 1203631340LL, 1227037003LL, 1250758849LL, 1274892125LL, 1299559906LL, 1324795149LL, 1350510875LL, 1376593435LL, 1403028629LL, 1429922644LL, 1457405859LL, 1485514730LL, 1514155683LL, 1543203181LL, 1572641892LL, 1602588815LL, 1633186342LL, 1664474165LL, 1696351486LL, 1728682008LL, 1761445285LL, 1794769597LL, 1828814019LL, 1863617807LL, 1899069884LL, 1935027797LL, 1971466974LL, 2008523557LL, 2046376390LL, 2085069567LL, 2124477324LL, 2164444125LL, 2204944946LL, 2246127897LL, 2288186708LL, 2331170910LL, 2374944919LL, 2419337740LL, 2464324227LL, 2510066877LL, 2556771251LL, 2604494051LL, 2653092123LL, 2702371962LL, 2752305410LL, 2803076889LL, 2854908075LL, 2907857789LL, 2961774353LL, 3016448100LL, 3071844250LL, 3128162791LL, 3185648506LL, 3244364764LL, 3304143118LL, 3364759211LL, 3426176909LL, 3488609875LL, 3552329115LL, 3617404129LL, 3683644973LL, 3750812077LL, 3818868910LL, 3888039623LL, 3958620113LL, 4030694695LL, 4104054622LL, 4178434675LL, 4253798862LL, 4330394472LL, 4408538904LL, 4488321060LL, 4569519033LL, 4651842318LL, 4735247672LL, 4820010876LL, 4906476594LL, 4994736912LL, 5084558311LL, 5175624602LL, 5267881025LL, 5361632211LL, 5457255131LL, 5554842531LL, 5654142432LL, 5754818741LL, 5856810174LL, 5960441397LL, 6066126885LL, 6173974428LL, 6283701754LL, 6394940039LL, 6507631461LL, 6622124245LL, 6738864791LL, 6857978989LL, 6979157639LL, 7101997795LL, 7226445406LL, 7352875310LL, 7481764169LL, 7613253926LL, 7747013059LL, 7882597151LL, 8019945383LL, 8159473589LL, 8301699931LL, 8446769883LL, 8594331579LL, 8743910527LL, 8895427207LL, 9049331616LL, 9206196601LL, 9366172128LL, 9528873964LL, 9693797200LL, 9860852104LL, 10030525166LL, 10203444811LL, 10379770883LL, 10559080583LL, 10740831340LL, 10924931305LL, 11111897941LL, 11302407501LL, 11496649064LL, 11694166218LL, 11894357291LL, 12097132737LL, 12303060819LL, 12512858130LL, 12726732383LL, 12944198756LL, 13164595478LL, 13387825436LL, 13614512988LL, 13845431958LL, 14080805456LL, 14320115376LL, 14562646835LL, 14808285424LL, 15057708438LL, 15311761934LL, 15570675608LL, 15833884237LL, 16100636108LL, 16370803829LL, 16645102455LL, 16924464220LL, 17209145957LL, 17498519429LL, 17791774046LL, 18088779028LL, 18390299936LL, 18697344550LL, 19010199275LL, 19328185010LL, 19650420611LL, 19976773039LL, 20308074230LL, 20645397422LL, 20989055317LL, 21338329924LL, 21692252275LL, 22050672926LL, 22414516095LL, 22784933595LL, 23162249395LL, 23545709392LL, 23934271129LL, 24327753869LL, 24727156223LL, 25133732686LL, 25547828658LL, 25968624018LL, 26395003862LL, 26826776509LL, 27265010674LL, 27711074049LL, 28165345366LL, 28626916844LL, 29094594714LL, 29568189289LL, 30048827936LL, 30537983178LL, 31036093648LL, 31542172860LL, 32054919139LL, 32574145537LL, 33101072871LL, 33637272712LL, 34183218205LL, 34737861066LL, 35299789674LL, 35868789249LL, 36446196097LL, 37033709594LL, 37631824690LL, 38239430818LL, 38855010405LL, 39478304136LL, 40110766887LL, 40754246129LL, 41409245858LL, 42074572214LL, 42748621670LL, 43431106384LL, 44123576445LL, 44828039580LL, 45545054957LL, 46273316616LL, 47011088823LL, 47758082837LL, 48515954457LL, 49286853483LL, 50071414346LL, 50868227777LL, 51675405572LL, 52492664809LL, 53321790300LL, 54165067429LL, 55023197297LL, 55894677570LL, 56777447396LL, 57671203191LL, 58577896159LL, 59499981893LL, 60438193000LL, 61390936476LL, 62356017675LL, 63333073337LL, 64324194785LL, 65332058203LL, 66357434382LL, 67398598180LL, 68453223508LL, 69520908559LL, 70603888232LL, 71705076914LL, 72825301246LL, 73962674804LL, 75114713008LL, 76281000319LL, 77463912237LL, 78666575137LL, 79889917242LL, 81131914957LL, 82389864969LL, 83663349085LL, 84954946378LL, 86267969252LL, 87603420299LL, 88959165726LL, 90332267436LL, 91722264269LL, 93131965301LL, 94564921811LL, 96022203051LL, 97501548558LL, 98999798351LL, 100516425306LL, 102054461912LL, 103617749612LL, 105207405771LL, 106820987034LL, 108455156577LL, 110109349227LL, 111786772339LL, 113491593995LL, 115225043914LL, 116984444361LL, 118766223652LL, 120569807381LL, 122398600243LL, 124257075520LL, 126146598389LL, 128064289941LL, 130006300065LL, 131972040551LL, 133965174080LL, 135990465810LL, 138049392322LL, 140138902214LL, 142254820391LL, 144396494515LL, 146567931024LL, 148774232292LL, 151016929662LL, 153292814315LL, 155597432252LL, 157930020989LL, 160294887144LL, 162697537961LL, 165139589171LL, 167617597202LL, 170126825416LL, 172666450793LL, 175241066390LL, 177856618213LL, 180514863855LL, 183212054568LL, 185943122312LL, 188707238814LL, 191509268101LL, 194355568996LL, 197248118105LL, 200182877692LL, 203154366440LL, 206161765751LL, 209210305125LL, 212306734650LL, 215453184594LL, 218645374888LL, 221877405056LL, 225148372390LL, 228463928649LL, 231831317974LL, 235252791803LL, 238723820584LL, 242238106889LL, 245794599859LL, 249399381601LL, 253060280355LL, 256779627993LL, 260552564683LL, 264372446164LL, 268238120513LL, 272156052482LL, 276134692273LL, 280176565688LL, 284276410040LL, 288427113649LL, 292627499395LL, 296884449016LL, 301206972463LL, 305597861214LL, 310051495326LL, 314560205170LL, 319122798205LL, 323746659718LL, 328441342645LL, 333209887681LL, 338046344401LL, 342942408883LL, 347896803977LL, 352917538518LL, 358014816334LL, 363191837821LL, 368442307795LL, 373757394476LL, 379135648951LL, 384585624470LL, 390118316230LL, 395737102460LL, 401435216507LL, 407203321410LL, 413039853891LL, 418953890989LL, 424957296394LL, 431053708853LL, 437235795593LL, 443493626599LL, 449825581962LL, 456241275517LL, 462753393721LL, 469365943387LL, 476071080066LL, 482858110773LL, 489725383995LL, 496683248414LL, 503745148015LL, 510915363490LL, 518185630677LL, 525544451047LL, 532990017359LL, 540533511079LL, 548189274537LL, 555961836768LL, 563842494708LL, 571818966004LL, 579889205275LL, 588065207835LL, 596362372780LL, 604785459785LL, 613325149310LL, 621968457024LL, 630713200422LL, 639572085807LL, 648561674937LL, 657687142087LL, 666938387037LL, 676301564345LL, 685774468635LL, 695370557493LL, 705107486530LL, 714990931444LL, 725010091661LL, 735150138513LL, 745408824452LL, 755800520881LL, 766343974694LL, 777045306277LL, 787893092424LL, 798871398499LL, 809977766202LL, 821227723044LL, 832641286737LL, 844224855443LL, 855966393492LL, 867848981159LL, 879869816425LL, 892045506340LL, 904397535591LL, 916932622159LL, 929637921709LL, 942495539191LL, 955502460050LL, 968676334546LL, 982040200877LL, 995601286295LL, 1009345773349LL, 1023254606037LL, 1037324694610LL, 1051574721415LL, 1066029208513LL, 1080696124591LL, 1095560713935LL, 1110602493920LL, 1125818361297LL, 1141228319560LL, 1156858331646LL, 1172716951103LL, 1188788582220LL, 1205051283087LL, 1221501719211LL, 1238161366709LL, 1255057902769LL, 1272200375557LL, 1289572315975LL, 1307150420390LL, 1324930934998LL, 1342936786986LL, 1361197671394LL, 1379723068032LL, 1398495392607LL, 1417490092525LL, 1436703101383LL, 1456158699765LL, 1475888764993LL, 1495903486004LL, 1516183934622LL, 1536703993094LL, 1557459476699LL, 1578476148379LL, 1599787909637LL, 1621405824525LL, 1643309773051LL, 1665471817396LL, 1687887677315LL, 1710584875844LL, 1733599281643LL, 1756942796500LL, 1780594225510LL, 1804523575124LL, 1828726241588LL, 1853231840544LL, 1878078521962LL, 1903278837236LL, 1928810454136LL, 1954641531896LL, 1980766953640LL, 2007218276106LL, 2034036325376LL, 2061234357322LL, 2088788516103LL, 2116665185001LL, 2144858936892LL, 2173403175320LL, 2202341606107LL, 2231688453890LL, 2261418067666LL, 2291494818317LL, 2321913119721LL, 2352708241781LL, 2383926705567LL, 2415584018270LL, 2447652863191LL, 2480095151903LL, 2512905159630LL, 2546120572871LL, 2579790652383LL, 2613931921957LL, 2648515601309LL, 2683501004908LL, 2718881926599LL, 2754698808770LL, 2791004040226LL, 2827815023108LL, 2865101499418LL, 2902820283286LL, 2940964457767LL, 2979577185567LL, 3018714402027LL};
int main(){
	int x;
	scanf("%d", &x);
	printf("%lld", ans[x]);
	return 0;
}
