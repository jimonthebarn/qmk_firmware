[private]
default:
    @just --list

# Compile default keyboard and keymap
compileDefault:
    qmk compile

# Compile keyboard {{keyboard}} and keymap {{keymap}}
compile keyboard keymap:
    qmk compile -kb {{keyboard}} -km {{keymap}}

# Flash Q6 ISO keyboard
compileQ6:
    qmk compile -kb "keychron/q6/iso_encoder" -km "jimonthebarn"

# Compile Q1 ANSI keyboard
compileQ1:
    qmk compile -kb "keychron/q1v2/ansi_encoder" -km "jimonthebarn"

# Flash default keyboard and keymap
flashDefault:
    qmk flash

# Flash keyboard {{keyboard}} and keymap {{keymap}}
flash keyboard keymap:
    qmk flash -kb {{keyboard}} -km {{keymap}}

# Flash Q6 ISO keyboard
flashQ6:
    qmk flash -kb "keychron/q6/iso_encoder" -km "jimonthebarn"

# Flash Q1 ANSI keyboard
flashQ1:
    qmk flash -kb "keychron/q1v2/ansi_encoder" -km "jimonthebarn"

# Compile and flash Q1 ANSI
Q6: compileQ6 flashQ6

# Compile and flash Q6 ISO
Q1: compileQ1 flashQ1
