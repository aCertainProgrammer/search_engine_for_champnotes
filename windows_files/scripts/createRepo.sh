#!/bin/bash

champions=("aatrox" "ahri" "akali" "akshan" "alistar" "amumu" "anivia" "annie" "aphelios" "ashe" "aurelionsol" "azir" "bard" "belveth" "blitzcrank" "brand" "braum" "briar" "caitlyn" "camille" "cassiopeia" "chogath" "corki" "darius" "diana" "drmundo" "draven" "ekko" "elise" "evelynn" "ezreal" "fiddlesticks" "fiora" "fizz" "galio" "gangplank" "garen" "gnar" "gragas" "graves" "gwen" "hecarim" "heimerdinger" "hwei" "illaoi" "irelia" "ivern" "janna" "jarvan" "jax" "jayce" "jhin" "jinx" "ksante" "kaisa" "kalista" "karma" "karthus" "kassadin" "katarina" "kayle" "kayn" "kennen" "khazix" "kindred" "kled" "kogmaw" "leblanc" "lee sin" "leona" "lillia" "lissandra" "lucian" "lulu" "lux" "malphite" "malzahar" "maokai" "masteryi" "milio" "missfortune" "mordekaiser" "morgana" "naafiri" "nami" "nasus" "nautilus" "neeko" "nidalee" "nilah" "nocturne" "nunu" "olaf" "orianna" "ornn" "pantheon" "poppy" "pyke" "qiyana" "quinn" "rakan" "rammus" "reksai" "rell" "renataglasc" "renekton" "rengar" "riven" "rumble" "ryze" "samira" "sejuani" "senna" "seraphine" "sett" "shaco" "shen" "shyvana" "singed" "sion" "sivir" "skarner" "sona" "soraka" "swain" "sylas" "syndra" "tahmkench" "taliyah" "talon" "taric" "teemo" "thresh" "tristana" "trundle" "tryndamere" "twisted fate" "twitch" "udyr" "urgot" "varus" "vayne" "veigar" "velkoz" "vex" "vi" "viego" "viktor" "vladimir" "volibear" "warwick" "wukong" "xayah" "xerath" "xin zhao" "yasuo" "yone" "yorick" "yuumi" "zac" "zed" "zeri" "ziggs" "zilean" "zoe" "zyra")


mkdir main_notes_folder

for champ in "${champions[@]}"; do
    mkdir "main_notes_folder/${champ}_notes"
    
    for other_champ in "${champions[@]}"; do
        if [ "$champ" != "$other_champ" ]; then
            touch "main_notes_folder/${champ}_notes/${champ}_vs_${other_champ}.txt"
        fi
    done
done

mkdir draft_notes_folder

for champ in "${champions[@]}"; do
    
    touch "draft_notes_folder/${champ}_draft_notes_enemy.txt"
    touch "draft_notes_folder/${champ}_draft_notes_ally.txt"

done