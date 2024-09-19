import os

def extractMethods():
    input_folder = os.path.join(os.getcwd(), 'public/public_raw')
    output_file = os.path.join(os.getcwd(), 'public/extCfgCam_methods.h')
    methods_fix = []
    methods_distributed = []
    methods_analytics = []
    methods_lite = []
    
    # Función para leer métodos de un archivo ignorando comentarios
    def read_methods(file_path):
        methods = []
        with open(file_path, 'r', encoding='utf-8') as file:
            for line in file:
                line = line.strip()
                if line.startswith('//') or not line:
                    continue
                methods.append(line)
        return methods

    # Leer y copiar los métodos de public_fix.txt
    fix_file = os.path.join(input_folder, 'public_fix.txt')
    methods_fix = read_methods(fix_file)
    
    # Copiar el contenido de public_fix.txt directamente al archivo unificado
    with open(output_file, 'w', encoding='utf-8') as output:
        for method in methods_fix:
            output.write('\t' + method + '\n')

    # Leer y añadir los métodos de distributed que no están en fix
    flag = 0
    distributed_file = os.path.join(input_folder, 'public_distributed.txt')
    if os.path.exists(distributed_file):
        methods_distributed = read_methods(distributed_file)
        for method in methods_distributed:
            if method not in methods_fix:
                with open(output_file, 'a', encoding='utf-8') as output:
                    if flag == 0:
                        output.write('\n\t##################################################\n')
                        output.write('\t################## Distributed ###################\n')
                        output.write('\t##################################################\n\n')
                        flag = 1
                    output.write('\t' + method + '\n')

    # Leer y añadir los métodos de analytics que no están en fix ni en distributed
    flag = 0
    analytics_file = os.path.join(input_folder, 'public_analytics.txt')
    if os.path.exists(analytics_file):
        methods_analytics = read_methods(analytics_file)
        for method in methods_analytics:
            if method not in methods_fix and method not in methods_distributed:
                with open(output_file, 'a', encoding='utf-8') as output:
                    if flag == 0:
                        output.write('\n\t##################################################\n')
                        output.write('\t#################### Analytics ###################\n')
                        output.write('\t##################################################\n\n')
                        flag = 1
                    output.write('\t' + method + '\n')

    # Leer y añadir los métodos de lite que no están en los anteriores
    flag = 0
    lite_file = os.path.join(input_folder, 'public_lite.txt')
    if os.path.exists(lite_file):
        methods_lite = read_methods(lite_file)
        for method in methods_lite:
            if method not in methods_fix and method not in methods_distributed and method not in methods_analytics:
                with open(output_file, 'a', encoding='utf-8') as output:
                    if flag == 0:
                        output.write('\n\t##################################################\n')
                        output.write('\t###################### Lite ######################\n')
                        output.write('\t##################################################\n\n')
                        flag = 1
                    output.write('\t' + method + '\n')

    print(f"Methods extracted and saved in {output_file}")

def mergeHeaders():
    properties_path = os.path.join(os.getcwd(), 'private\\extCfgCam_properties.h')
    methods_path = os.path.join(os.getcwd(), 'public\\extCfgCam_methods.h')
    unified_path = os.path.join(os.getcwd(),'extCfgCam.h')
    # Leer el archivo de propiedades
    with open(properties_path, 'r') as properties_file:
        properties_lines = properties_file.readlines()

    # Leer el archivo de métodos
    with open(methods_path, 'r') as methods_file:
        methods_lines = methods_file.readlines()

    # Crear el nuevo archivo unificado
    with open(unified_path, 'w') as unified_file:
        public_found = False

        for line in properties_lines:
            unified_file.write(line)

            # Cuando encuentres 'public:', insertar los métodos
            if 'public:' in line and not public_found:
                public_found = True

                # Insertar líneas de métodos antes de '};'
                for method_line in methods_lines:
                    unified_file.write(method_line)

        # Agregar cierre de la clase si falta
        if not any('};' in line for line in properties_lines):
            unified_file.write('};\n')

    print(f"Headers successfully merged at {unified_path}.")

