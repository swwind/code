#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(int argc, char const *argv[]){
	printf("%d\n", 'o'-'a');
	return 0;
}
#if 0
VAN 保佑我NOIP一等

$=***!!;;!!!**!*!;;*=$$$$====##@#$$=====$$$$==$$!;:~~~~
$=***!!;;!!!!!*!!:*=$$===*=$@@@@@@@$===$$###$=$$*;:~~~~
=****!!::!!!!!!*!;;*$###$$=@@@@@@@@@#=====$===$$*;:~~~~
=****!*;;***!***!;;*$####$#@@@@@@@@@@#========$$*;:~~~~
=**$=!*;;!!*****!;;*$###$=#@@@@@@@@@@@==$$$$==$$*;:~~~~
=**==!*:;!!;:!!!!;;*$$#$$=######@#@@@@========$$*;:~~~~
=****!*:;;;;;;;;;;:*$$$$$=#=!!*==$#@@#=========$*;:~~~~
=***!!*;;;:;;;;;;;;!$$$$===~-,~--;#@@$=====$=$$$=*;:~~~
=*!!!!*;;::;;;;;;;;!$$$$$$!;:,,,,~$@@======$$$$=$$!;;:~
=***!!*::::;;;;;;;;!$$$$$$:;-:~;:;*#======$$$$$$$$*!!;:
=*!!!!!;:::;;;;;;;;!$$$$$$;,-..~-~*$*=====$$$$$=$$*!!!;
=!!!!!!;:::;;;;;;;;!$$$$$=*,, ...-**======$$$$$=$$*!!!;
=!!!!!!;:::;;;;;;;;!$$$$==!--,.,,:*=======$$$$$=$$*!!!;
=**!!!!;:::;;;;;;;;!$$$$=::~,,,-~;*======$$$$$$=$$*!!!;
=**!!!!;::;:;;;;;;;!$$$$*;*;~;!-:*=======$$$$$$$$$*!!!;
=**!!!!;::;;;;;;;;;;$*::,,;*~--~!$=======$$$$$$$$$*!!!;
=**!!!!;::;;;;;;;;::-,~,,--~;~~!##=======$$$$$$$$$*!!;;
$*!!!!!;;:;;;;;::~-...-,,--~$$=#$#=======$$$$$$$$$**!!:
$*!!!!!;;:;;;;::-  ..,.!:,,-;!=#$,$*=====$$$$$$$$$*!!;:
$**!!!!;;:;;;;:-.    - ,=!,,,-*!**;==*=$$$$$$$$$$$*!!:~
$*!!!!!;;;;:;:-.    .-  .;=,-~:;*==$#===$$$$$$$$$$*!;:~
$*!!!!!;;;::;:-.    -    ,-*~~~:!**##$!*==$$$$$$$$*!;~~
$*!*!!!!;;;;;:,.. ..~.   .:~!:-,:*#$$=*!*=$$$$$$$$*!:~~
$*!*!!!!;;;;:~,...,-,     .*,=,,:$=$*=*;!=$$$$$$$$*!;~~
$**!!!*!;;;::~-,,,~~.     .,**!-$==;;!!;!=$$$$$$$$*!;:~
$**!!!*!;;;:~,-,,,:~       .~=**$=;:;!*!!*$$$$$$$$**!;:
$**!!!*!;;;:-.,,. !-        ,-:,:;~~:!=*;*$$$$$$$$=**!;
#**!!***;;;:-.....*-,.      ,:=~-~~~:!==!*$$$$$$$$=**!!
#**!!***;;;~-....,=;~-......~$#=--~~;!=*!*$$$$$$$$=**!!
#**!!***;;;~,...,~=;!:::,,--*=*;~~~:!*=!!*$$$$$$$$=**!!
#**!!!**;;;~,...,;#*;=**!;;:!$$!::;!*=$!!*$$$$$$$$=***!
#**!!!**;;;~,..,-=***$=.;!=*,:=$==*=$#=;!*$$$#$$$$=***!
#**!!!!*;;;-...,-!;,. .:!==*--$#$#####*!!=$$$##$$$=****
#***!!!*;;:-..,-:!;,.   ..,.,-;$$###$$*;!*$$$##$$$=****
#**!!!!*;;:,.,-~;!;,.       ..-:;*=$$$*;;*$#$##$$$=****
#**!!!!*;;~. ,~:;*!-.       ..,~;*=$$$*;;*$#$##$$$=****
#=**!!!*;:-..-~;;*!~,...    ..,~!*=$$$*;:!$$$###$$=****
#=*!!!!*;:-..-~;!**~-,,,......-;*==$$$*;:;=$$###$$=****
#=*!!!!*::, .-:;***~-,,......,-:**=$#$*;:;*$$####$=****
#=*!!!!*:~, .-:;***~,....  ...,:!==$#$=;;:;=$####$==***
#=*!!!!!:~,..-;;*!!~,.......,.,;**=$$$=;;::=$#####$=***
#=*!!!!!:-,..-;!*!!~.. ....,~--!=**$$#$;:~~*$#####$=!!*
#=*!!!*!;~,..~;!*;*;-.........-!=*$###=;~-~*$#####$=!!*
#=*!!!!!;~,,,:;!==$$*:~---;;-:;*=$#@##=:-,-*$#####$=!!*
#=*!!!!!*#**$$;!*=$##$$$=$=#-:;*$#@@@#=~-,~*$#####$=!;*
#=*!!!!!*#*=##;!**$##=*=!;~$.-!$$#@@@#=~--:=$#####$=!;*
#=*!!!!!*#*=#$;***###$$###=$~,,*$$@@@#=~--:=$#####$=!;!
#=*!!!!!*#*=#*;**=###$$=$$#####@@@@@@#=:~~;=######$=!;!
#$*!!!!!*#*=@!!*==##$====$#####@@@@@@#$=*!!$######$=*;!
#$*!!!!!*#*=@;;*=*###=$$$$$#$$$@@@@@@###;=@@######$=*;!
#$*!!!!!*#*=@;-;!=##$=$$$====$#@@@@@@###=$@@######$==!!
#$*!!!!!*#*=@;;!*$###$$$$$$$==##@@@@@@##$$@@######$$=!*
#$*!!!!!*@*$$;;!#@#=====$$====#@@@@@@@###$@@######$$=!*
#$*!!!!*##===;;!@@$==$$$$$$$$$#@@@@@@@$#=$@#######$$=**
#$***!!!!=;:;;;*##*;===$$$$$##@@@@@@@@#@@$@########$=**
#$***!!!;-..-;:$##=*$$####@##@@@@@@@@@###$@########$==*
#$***!!!;,..,;!###;!$==$##@@@@@@##@@@@#@#$@########$==*
#$***!*;;--~~;*##$**=$####@@@@####@@@@#$##@########$=*!
##*****;;-~::;$##$*$*=##@@@@@@####@@@@#==#@########$==!
##*****!!~:;~;###==$!$##@@@@@@####@@@@$~-*#########$==!
##*****!!;~;:!##$====$#@@@@@@@####@@@#*--;$########$$=*
##*****!!;:!**##$=$*$##@@##@@@@###@@@#*::;$########$==!
##*****!*::;;###$=$!$#@@@##@@@@###@@@#!!!;$########$==!
##=****;*;;;;###==$!$#@@@##@@@@###@@@#:=!:$#####$$#$==!
##=****!*;;;;###===!##@@@##@@@####@@@$~$-=######!:;=$=!
##=****!*;;;;##$*===#@@@###@@@###@@@@$!~!$#@@##@#=$$##@
##=****!*;;;!##$*$=$@@@@###@@@###@@@@$*==#@$@##$@#**$#@
##=****!*;;;!##$**$#@@@####@@@###@@@@##$###$#@#@##@@@##
##=****!*;;;$##$$$!##@@####@@@###@@@#######@#@@#@@$####
##=****!*;;;###=*=!#@###@#@@@@##@@@@######@##@###$#####
##=****!*;;!##$====#@#@#@#@@@@###@@@###########~######@
##$****!*;;;##$===######@#@@@@@##@@#######$###$@#####@@
##$****!*;;!##$$##@#=###@#@@@@@##@@######=##@=@######@@
##$****!*;;=#$=#$##@=######@@@@@@@@#####$#$#######@##@@
##$****!*;;$#######@$######@@@@@@@@###$$$##@$@@@@@@@@@@


王保佑我NOIP一等

~-~------,--,-,-~-,-,--,-~:;!:-:-,=;:*=*!~,-~~~:~~:~~~~~~~~~~~~~~~~~~~~~~~:~~:~:::~:~~::;:
----~-~-~,,,,-~~,,-,--,--;.;!~~=!!*$*$$!!!=;~~-,~-~~~~~-~~--~~~~~~~~::::~~:~::;;:::;:::~::
--,-,,---,-,,-,,,----,--:!-===*#$$###$=!=$==;,---~--,--~~----~~~~~::~:~~~~::~::~:::~::::;:
----,,,----,-,,.--,--,,~!!;##$$####@@@$##$$$!~~-~~--,--~-~-,--~::::~~~:~:~::~:::::::;:~:;:
---,,,,-,,,-,,,,,,,,,,.-!!=$@###@#@@@@@@#$##=:~~-,-,-,-----~~~:;~~:::::~~~~~~~~~~::::~:-::
---,,,,,,,,,,---,,..,..~*=$#########@@@@@#@@@#~-~,-,,--~~~~~~~~~:~~~~~:~--~::,~--~~~~~~~:~
--~,.,,,,--,--,,,,,,~.~;=$$#$$$===$$==$###@@@@!--~--.-----~~~~-~,----~~~--:~~----~-,~,~:~~
-,,,,-----,,,-,,,,,-:~-;*$$$=*!;;:!!!*==$#@@@@$--,-,--~~-~:~--,-~,---~~~:::--~--~---~::~:~
-.,,-,~-~-,,-,.,,,,~;**!=$$*!::~,.,,-;**=$#@@@@:-,,--,,,--------,-,----:~~--~---~~~~~~:~~~
,,,..,,,---,,,,.,,,~!=*!**!!:--,. ..,~;!*=$#@@@*,,,,,,,~,----,-~-,---:~~-~~----,---~::::;~
,-,,-,-,,,,--,,,-,-:;**:--~~--,,....-~:;**=##@@#-,--,,~,,-,,----,,~~:---~------,,-~::::~::
:-~~~,~-,.,,,,,-.,-:;!:-,.-.,-......,-~:;**$####--,-,,,-,,-,,,---~~~-------------~~~-;:~:-
~-,---~,,,.,-,~-,,~;;~-:,----.......,-~:!!*=$$#@;-,,-,----,,----::-,-------,--~-,-~~,:~-~-
----~~~~--,,-::~~-.::~-,..,,. ......,--~~;**=$##=-,,-,,-~----,--~-,-~-~---,---~~-~:~~:~:~-
~--,~--,-,-.,----,-;~:~,..., ... ...-~~-~:!*==$##-----~---,.,,-------,---------~;;~::::~~-
~-,-~-.-,-.,-,,,,-~;;~-..-.    ....-~:;!!==**=$#@~-.--,---~---.,-~-----~----~--:;:::~~:~~~
~--,-,--,,,-,,,,---*;;~,.,.    ..,-;*$$$====**=##=;-,,,~~,-~-,,-------------~~~!:~;;~:~~~~
--,,-,,--,,-,,,,---!!!~,..  ...,-~~*===********$#=*:,,,---.-,,-,-,-,-,-~------::::!:~~~-~-
~,-,,-,,,--,,--~----=*:,.. ..,~:::;!!===$$=****=#***--,-~,-,,,,------,-,---,-;::~:!~---~--
~:-,-,,.--,.,,,,---~*=;,.  .-!**;::!*=$$=*******$*!!;,,-,---,,,,,,-,-,-----~~::~~;;:--~-~-
~--,~-,,,,,,,.--,--~:=!~. ,:=$**;-.~**=*********=$$**,,,--,~-,--~,-.,,-,-,-~-:~-:,~---~~--
~-,,-~-.--,.--,------*!:.,:*=***!, ,;!=**!!!!***==*=*,,,,-,--,,-,--------~~~:::~-~~-----~-
,,-,---,,-,,-,-,--,-,-=!,-!!!=$=!. ,:;;!!!!!!!***$**!,,-,,,,,,,,-,----,,---~;:~;,~-~~-~---
,,,-~~-,,--,,-,~--,--,:*.-;;==!*;. .~;!;:!!!!!**==**!,,-,--,,--,--,-,-,---~::~:!--~~~-~~--
.,,,-~:~,,.-,,,,,,----,!-,~!;!!;..  ,;!!:~;!!****=**!,,-~,,,,,--,----,----::::;~~~-~~-~-~-
--,,,--~,,,---,,,-,,-,,,;.,--~~,..  ,;~;;:;!******=*:,,-,,,,-~----,--,-,-:!;;;:~~---~~-~~-
,-,,,,,,,,.,,,,,-,,,,,,,.... .. ....~!;!!;;!!*******-,-,-,,,~~~-~---,,,,~;!;;;;~-~--:~~~:-
,-.,~-,.--,,,,,,,,--,-,,~,...,. ..,::*$***;!******=*;;:~~~-~~-~,~-,-,,--~::::~~~~-~--:~---
----,,-~,----.,-,,,,-,,.~~,,,,. ,-~*;;*=***;********;~~~~~-~-----,,----~~~~-;-~-~--~~~----
-~~~-:~-:--,.-,-,,,,,.,,,,,,,,,.,:.!!!**=***********;~--~~-~--,---,----!;~~~,:--~~~~:--~~~
-,-~,:----,-,,~--,,,,,,.,.~,--,,-- -:=*!*!!!!****=*=!,---~-----~----:-~~::::;~,~~--~~-,~~~
--,-,--,,-,,~,-~,,,,--,,,..,--,--. ,,-:!!!******==***~-,---,-,-----~~~*:~:~-~~~~:~~---~-~~
-------,,,,-,-~,,,,,-,-,-, .-~-,,.,,:!!==*******====**----~,---~,--~:~!~-~-:~-~---~--~,---
-------.-,,-,--,,,,,,,,,,-..-~-,,,-:*:,-;!!*!*=*====*==--~,----,,--~::~-:~-~-,,-~~-----,~-
~--,---,-,,--,~.,.-,,,,,,,,.-~~,,-:*-,~;!!!!*=======*==*:-,-,---,-,;~;:~::,~,-,-,~~---~--;
~~---~,----,~,,,-,-,,,,-,,---~:-,-;:-~!*****========**==*~--,-,-,-~;;:-::~,.-~:-~-----,-:~
~-,-~--~----,.--,~,,,.,-,--~-~:~,-;::;!*============*===**:-------~:;:-:~~--~:-~,,-~--,-~-
--.~~,~-,---,,--..,--,,~~--~--::~~;;!;;;***=========**====*=~,~~~:!!~-:~,----~--,----,:;;~
--.~~-~~,--~,--,-,--~--,---~--~~;;;!;~--:!**=*====****=====*=*::!*!;:~::~--!----,----,-~!:
~---,----~------~-~-,,--~--~~~~,~;;;:~:;!***======****=====****!**;::~;-~,~;:,,~~-~~-~-;;~
~~-~:~~--~~-,-----~,-,-~~~-~-~~~,:!!;~;****===*=******=====*=******~~~;~~,,:-~-:---~~~~!:-
~-~-:~----~-,--~-----,~~-~-~-~,. .~;!!!****=**==*******==**********!~~-----~---~-,---~--,-
~-~--~---~--,,~-~--,,-~---:-,.    --;;!****************==******!!**!*;------~-~-,-,----,,-
~~~----:~~~~-~~,------~----.       -~;!!!!!*****************!!!!!****!!;-:-:~,~:--:~~;~,-~
~-~~~~~~~--:-~-----------.         .~~;!!!!!!**************!!!!!!!!***!!!:--~~-~-,~~:;-,,-
~-:~~~-~~:~~::---.......  ..       .--~;;;!!!!!!**********!!!!!!!!!!!***!*!--~-,,-~~;--,--
~:~~~~-~,~-~-~~,   ....     ...    .,-~;;;!!!!!!*********!!!!!!!!!!!!!**!***~-,,--~~--~~--
~:~~~~~~~-:-~~     ...      ...    . -~:;;;!!!;!!*********!!!!!!;!;!;!!******:~-~~~;;~~~~-
:!~~:-~~,~---      ...     ...,. ..  --:;;;;!;;!!********!!!!!!;;;!;;;;!*****=:~~~;;;~~--~
:~:~-::---~-       . .   ....,,  .,  .-~;;;;;;!!!********!!!!!!;!;!;;;;;;!!**!*~~:~;::~~~-
:;::~---~:-          .   ...,,.  ...  ,~;;!!;;;!**********!!!*!!!!!;-.....,-~:::~~~;:::~~~
:~~~~~~~~~.         .   ..,,,,.   ... ,-;!!;;;;!*************!!!!!;........,,------:~;;~~:
:;~~~~-~~,        . . ....,,,,      . .-:!!!;;;!****==****!!!!!!!;-    ....,,,--~-~~~::~~-
:;~:~-~-~         ..  ...,,,,.      .. ,~;!!;--;!!**!!!!!!!!;!;;;;.     ....,,,-~~:::;::~~
~~~~~~~:,        ... .....,,..      ....-:;;. .,;;;!!!;!!!!!!;;;;-       ..,,,,-~::;;!!:::
~:-:;-~~.        .......,,,...  . . ....-~~,... .~;;;!!!!!!;;;:~,        ...,,,--::;!*!!::
~::::::~         ......,,.... .  .   ..,,,,. .   .,:;!!!!!!;;-          ...,,,--~:;!!***!:
~:;:::;,         . ....,......... .  ..-,...     ...~;;!!!;;-            ..,,,,-~:;!!****;
~;:::::    ...  ................. .. ..,,.,.    .....,~;;;;,           . ...--:~::;!*****;
~;;;~::... ...  .................... ..,,,.    ..... . .-~.            . ..-~:::;:;!*****;
~;;:;:~,...................,..,...... .,,.          .    .              ...-~::;;;;!*****!
;;:;::-.....................,,,......,,,,..    .  . .                 ....-:::;;!;**!****!
:;:;;:,..,.......,........,,,,........,,,.... ..  .                   ..,.,-::!;!;*******!
!;!!;;,,,.,.....,,.......,,,,,...,..,,,,,.  ......   .               ....,,~~~;;;!*******!
;~;;;;,..,,,....,,,.,,..,-,,,....,..,,,,,... . ...                  .....,---~;:;!*******!
!:;!::,,.,,,..,,-,,,.,,,,-,...,.,,,,,--,.. .......                 .....,,,,-~;;!!*=*****!
!;;;::. ..,.,,,,~,,,...,.,-.,,.,,,,,----,..... ... .           ........,.,,,-:;!*!*$*****!
;;;!;, ...,.,,,-~--,....,.,..,,,,.,--~--,... ....       ..     .......,,,,,,:~;!*===*****!
;::::  ...,,,,-~:~~.....,...,.,,,,-~:::-,.....          ............,,,,,,,-:;!**====****!
;!::    ...,,-~:;::,....,.,,.,.,---:~;:~....      ..  .............,,,,,,,,--~:;!*==$****!
!;:,     ...,,-:!*:,...,,,,,,,-,-~~~:;;,,....,..  ...............,,,,,,,,,---~:;!!!==****!
!::         .,-:;!!,...,,..,---:~~:::;;-,,.,... .. .  ..,,.,,,.,.,,,----,,--~~:;!!!!!****!
!:-         .,-~;!*-,....,,--~~::~~:;;;~-....... . .....,,,~,-,,,,,--------~~::;!!!!!****!
!:         .,,-~;!*:,....,--,-:~~~:::;;--..............,,--~~~-------------~~::;!!!!!****!
;,         ,,,-~;!!*-,,,,,--~:;~~::;:!!~,.,........,.,,---~~::~~----~~-----~~::;!!!!!****!

#endif