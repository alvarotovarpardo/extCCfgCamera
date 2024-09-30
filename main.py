import sys
import os
import subprocess
sys.path.append(os.path.join(os.getcwd(), 'Code'))
from modules import isolateClasses, isolatePrivate, isolatePublic, copyFilesToC_Code, createConfigBaseHeader, createConfigBaseCpp, compareExcel
from extCfgCam_initDefault import copyInitParams, createInit
from extCfgCam_properties import processClean, masterAttributes, tableAttributes, readExcel, write_header_file, deleteBuildFolder
from extCfgCam_methods import extractMethods, mergeHeaders, unifyEnums

################################### PROPIEDADES ##################################################

# Se debería hacer un fetch antes de nada

# El orden debe ser: Fix, Distributed, Analytics, Lite

header_files = [
    r"C:\Users\Projects\sw_redlook_Fix\gui\util\config_camera.h",
    r"C:\Users\Projects\sw_redlook_distributed\gui\util\config_camera.h",
    r"C:\Users\Projects\sw_redlook_analytics\gui\util\config_camera.h",
    r"C:\Users\Projects\sw_redlook_Lite\gui\util\config_camera.h"
]

cpp_files = [
    r"C:\Users\Projects\sw_redlook_Fix\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_distributed\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_analytics\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_Lite\gui\util\config_camera.cpp"
]

header_config_base = [ r"C:\Users\Projects\sw_redlook_Fix\gui\util\config_base.h"] # Nos basta con el del Fix.
cpp_config_base = [ r"C:\Users\Projects\sw_redlook_Fix\gui\util\config_base.cpp"] # Nos basta con el del Fix.


# Leemos las propiedades de las clases directamente extraidas de los .h para todas las aplicaciones
isolateClasses(header_files) # Aislamos la clase CCfgCamGeneral en header/class_raw
isolatePrivate() # Separamos las propiedades (private) en header/build/private/private_raw. 
isolatePublic() # Separamos los métodos (public) en header/public/public_raw

# Limpiamos private_raw (separamos multidefiniciones en una línea, eliminamos comentarios, espacios, ...). 
# Se crea:
    # header/private/build/private_clean, con propiedades acompañadas del tipo de dato
    # header/private/build/private_reduced, con propiedades sin prefijo (m_i, m_b, ...) ni tipo de dato. Esto servirá para ver si existen atributos nuevos 
    # que no aparecen en la documentación. 
processClean()

# Ordena por orden alfabético las propiedades de:
    # private_clean si False 
    # private_reduced si True
# y lo guarda en header/build/private_sorted
# Creamos all_private.txt conteniendo todas las propiedades de todos los SWs sin repetirse, por orden alfabético,
# leídos de la carpeta private_sorted.
masterAttributes(False)

# Creamos un Excel con todas las propiedades indicando en qué SW se encuentra.
# Si False, lee private_clean
# Si True, lee private_reduced
tableAttributes(False)

# Leemos el Excel junto con qué SW se encuentra. Esto servirá para clasificarlos en la clase y compararlos con los atributos de la documentación
readExcel()

# Escribimos el header especificando en qué SW se encuentra
write_header_file()

# Como nos interesa escribir un header indicando el tipo de dato, masterAttributes y tableAttributes empiezan
# con el parámetro False. Una vez escrito el header, repetimos con True para obtener all_private.txt y el Excel
# sin indicar el tipo de dato. Más que nada por checkear que está todo en orden.
masterAttributes(True)
tableAttributes(True)

# Borramos todos build folders if True. 
deleteFolder = True
deleteBuildFolder(deleteFolder)


# Comparamos las propiedades del Excel Redlook_attributes.xlsx con las generadas
# input: path a Redlook_attributes.xlsx
RedlookAttributes_path = r"C:\Users\ÁlvaroTovarPardo\OneDrive - Sensia Solutions SL\Redlook_attributes.xlsx"
compareExcel(RedlookAttributes_path)
################################### MÉTODOS ##################################################

extractMethods() # Creamos .h en public con los métodos para incluirlos más tarde junto a las propiedades
unifyEnums() # Separamos los enums para incluirlos de manera unívoca (los objetos contenidos en Enums varían entre SWs)

################################## MERGE PROPERTIES & METHODS #################################

# Creamos la clase final
mergeHeaders()


########################## INITIALIZE PARAMS: initDefault() ##################################
# Creamos config_camera.cpp con la función initDefault(). 
# i.e., inicializamos las variables

# Llamada a la función para copiar el contenido
copyInitParams(cpp_files)
createInit()

######################## config_base.h // config_base.cpp ####################################
createConfigBaseHeader(header_config_base)
createConfigBaseCpp(cpp_config_base)


################################# COPY C++ FILES #############################################

# Estaría bien meter todo a la carpeta C_code para no tener que hacerlo a mano.
copyFilesToC_Code()