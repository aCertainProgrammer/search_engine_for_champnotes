#!/bin/bash

champions=("aatrox" "ahri" "akali" "akshan" "alistar" "amumu" "anivia" "annie" "aphelios" "ashe" "aurelion sol" "azir" "bard" "bel'veth" "blitzcrank" "brand" "braum" "briar" "caitlyn" "camille" "cassiopeia" "cho'gath" "corki" "darius" "diana" "dr. mundo" "draven" "ekko" "elise" "evelynn" "ezreal" "fiddlesticks" "fiora" "fizz" "galio" "gangplank" "garen" "gnar" "gragas" "graves" "gwen" "hecarim" "heimerdinger" "hwei" "illaoi" "irelia" "ivern" "janna" "jarvan iv" "jax" "jayce" "jhin" "jinx" "k'sante" "kai'sa" "kalista" "karma" "karthus" "kassadin" "katarina" "kayle" "kayn" "kennen" "kha'zix" "kindred" "kled" "kog'maw" "leblanc" "lee sin" "leona" "lillia" "lissandra" "lucian" "lulu" "lux" "malphite" "malzahar" "maokai" "master yi" "milio" "miss fortune" "mordekaiser" "morgana" "naafiri" "nami" "nasus" "nautilus" "neeko" "nidalee" "nilah" "nocturne" "nunu" "olaf" "orianna" "ornn" "pantheon" "poppy" "pyke" "qiyana" "quinn" "rakan" "rammus" "rek'sai" "rell" "renata glasc" "renekton" "rengar" "riven" "rumble" "ryze" "samira" "sejuani" "senna" "seraphine" "sett" "shaco" "shen" "shyvana" "singed" "sion" "sivir" "skarner" "sona" "soraka" "swain" "sylas" "syndra" "tahm kench" "taliyah" "talon" "taric" "teemo" "thresh" "tristana" "trundle" "tryndamere" "twisted fate" "twitch" "udyr" "urgot" "varus" "vayne" "veigar" "vel'koz" "vex" "vi" "viego" "viktor" "vladimir" "volibear" "warwick" "wukong" "xayah" "xerath" "xin zhao" "yasuo" "yone" "yorick" "yuumi" "zac" "zed" "zeri" "ziggs" "zilean" "zoe" "zyra")


mkdir main_notes_folder

for champ in "${champions[@]}"; do
    mkdir "main_notes_folder/${champ}_notes"
    
    for other_champ in "${champions[@]}"; do
        if [ "$champ" != "$other_champ" ]; then
            touch "main_notes_folder/${champ}_notes/${champ}_vs_${other_champ}.txt"
        fi
    done
done
