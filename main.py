import sys
import os
import shutil
sys.path.append(os.path.join(os.getcwd(), 'header\\private'))
sys.path.append(os.path.join(os.getcwd(), 'header\\public'))
sys.path.append(os.path.join(os.getcwd(),'initDefault'))
from extendedInitDefault import copyInitParams, createInit
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


########################## INITIALIZE PARAMS: initDefault() ##################################
# Rutas a los .cpp de todos los proyectos
input_files = [
    r"C:\Users\Projects\sw_redlook_Fix\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_distributed\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_analytics\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_Lite\gui\util\config_camera.cpp"
]


# Llamada a la función para copiar el contenido
copyInitParams(input_files)
createInit()

################################# COPY C++ FILES #############################################

# Estaría bien meter todo a la carpeta C_code para no tener que hacerlo a mano.
current_dir = os.getcwd()

c_folder = os.path.join(current_dir, 'C_code')

header_file = os.path.join(current_dir, 'header\\config_camera.h')
cpp_file = os.path.join(current_dir, 'initDefault\\config_camera.cpp')
config_base = os.path.join(current_dir, 'config_base.h')

# Verifica si los archivos existen y realiza la copia
if os.path.exists(c_folder):
    if os.path.exists(header_file):
        shutil.copy(header_file, c_folder)
        print(f"'{header_file}' copiado a {c_folder}")
    if os.path.exists(cpp_file):
        shutil.copy(cpp_file, c_folder)
        print(f"'{cpp_file}' copiado a {c_folder}")
    if os.path.exists(config_base):
        shutil.copy(config_base, c_folder)
        print(f"'{config_base}' copiado a {c_folder}")
else:
    print(f"La carpeta {c_folder} no existe.")