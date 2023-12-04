@echo off
setlocal enabledelayedexpansion

set "champions=aatrox ahri akali akshan alistar amumu anivia annie aphelios ashe aurelionsol azir bard belveth blitzcrank brand braum briar caitlyn camille cassiopeia chogath corki darius diana drmundo draven ekko elise evelynn ezreal fiddlesticks fiora fizz galio gangplank garen gnar gragas graves gwen hecarim heimerdinger hwei illaoi irelia ivern janna jarvan jax jayce jhin jinx ksante kaisa kalista karma karthus kassadin katarina kayle kayn kennen khazix kindred kled kogmaw leblanc lee_sin leona lillia lissandra lucian lulu lux malphite malzahar maokai masteryi milio missfortune mordekaiser morgana naafiri nami nasus nautilus neeko nidalee nilah nocturne nunu olaf orianna ornn pantheon poppy pyke qiyana quinn rakan rammus reksai rell renataglasc renekton rengar riven rumble ryze samira sejuani senna seraphine sett shaco shen shyvana singed sion sivir skarner sona soraka swain sylas syndra tahmkench taliyah talon taric teemo thresh tristana trundle tryndamere twisted_fate twitch udyr urgot varus vayne veigar velkoz vex vi viego viktor vladimir volibear warwick wukong xayah xerath xin_zhao yasuo yone yorick yuumi zac zed zeri ziggs zilean zoe zyra"

mkdir "%~dp0..\main_notes_folder"

for %%A in (%champions%) do (
    mkdir "%~dp0..\main_notes_folder\%%A_notes"
    
    for %%B in (%champions%) do (
        if /I "%%A" neq "%%B" (
            type nul > "%~dp0..\main_notes_folder\%%A_notes\%%A_vs_%%B.txt"
        )
    )
)

mkdir "%~dp0..\draft_notes_folder"

for %%A in (%champions%) do (
    type nul > "%~dp0..\draft_notes_folder\%%A_draft_notes_enemy.txt"
    type nul > "%~dp0..\draft_notes_folder\%%A_draft_notes_ally.txt"
)
