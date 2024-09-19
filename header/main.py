import sys
import os
sys.path.append(os.path.join(os.getcwd(), 'private'))
sys.path.append(os.path.join(os.getcwd(), 'public'))

from extCfgCam_properties import processClean, masterAttributes, tableAttributes, readExcel, write_header_file, deleteBuildFolder
from extCfgCam_methods import extractMethods, mergeHeaders, unifyEnums

################################### PROPIEDADES ##################################################

# Leemos las propiedades de las clases directamente extraidas de los .h para todas las aplicaciones
# y limpiamos (separamos multidefiniciones en una línea, eliminamos comentarios, espacios, ...). 
# Se crea:
    # private_clean, con propiedades acompañadas del tipo de dato
    # private_reduced, con propiedades sin prefijo (m_i, m_b, ...) ni tipo de dato
processClean()

# Ordena por orden alfabético las propiedades de:
    # private_clean si False 
    # private_reduced si True
# y lo guarda en private_sorted
# Creamos all_private.txt conteniendo todas las propiedades de todos los SWs sin repetirse, por orden alfabético,
# leídos de la carpeta private_sorted.
masterAttributes(False)

# Creamos un Excel con todas las propiedades indicando en qué SW se encuentra.
# Si False, lee private_clean
# Si True, lee private_reduced
tableAttributes(False)

# Leemos el Excel junto con qué SW se encuentra
readExcel()

# Escribimos el header especificando en qué SW se encuentra
write_header_file()

# Como nos interesa escribir un header indicando el tipo de dato, masterAttributes y tableAttributes empiezan
# con el parámetro False. Una vez escrito el header, repetimos con True para obtener all_private.txt y el Excel
# sin indicar el tipo de dato. Más que nada por checkear que está todo en orden.
masterAttributes(True)
tableAttributes(True)

# Borramos build folder if True. 
deleteFolder = True
deleteBuildFolder(deleteFolder)


################################### MÉTODOS ##################################################

extractMethods() # Separamos métodos y creamos .h en public para incluirlos más tarde
unifyEnums() # Separamos los enums para incluirlos de manera unívoca

################################## MERGE PROPERTIES & METHODS #################################

mergeHeaders()