import os
import re
from collections import defaultdict

def extractMethods():
    input_folder = os.path.join(os.getcwd(), 'public/public_raw')
    output_file = os.path.join(os.getcwd(), 'public/extCfgCam_methods.h')
    enum_output = os.path.join(os.getcwd(), 'public/enums.txt')
    
    methods_fix = []
    methods_distributed = []
    methods_analytics = []
    methods_lite = []

    # Función para leer métodos de un archivo ignorando comentarios
    def read_methods(file_path):
        methods = []
        enums = []
        with open(file_path, 'r', encoding='utf-8') as file:
            for line in file:
                line = line.strip()
                if line.startswith('//') or not line:
                    continue
                if 0 <= line.find('enum') < 10:
                    enums.append(line)
                    continue
                methods.append(line)
        return methods, enums

    # Leer y copiar los métodos de public_fix.txt
    fix_file = os.path.join(input_folder, 'public_fix.txt')
    if os.path.exists(fix_file):
        methods_fix, enum_fix = read_methods(fix_file)
    
        # Copiar el contenido de public_fix.txt directamente al archivo unificado
        with open(output_file, 'w', encoding='utf-8') as output:
            for method in methods_fix:
                output.write('\t' + method + '\n')
            
        with open(enum_output, 'w', encoding='utf-8') as output:
            output.write('\n\t#################### Fix #######################\n\n')
            for enum in enum_fix:
                output.write(enum + '\n')
    else:
        print(f"Fix file {fix_file} does not exist.")

    # Leer y añadir los métodos de distributed que no están en fix
    flag = 0
    distributed_file = os.path.join(input_folder, 'public_distributed.txt')
    if os.path.exists(distributed_file):
        methods_distributed, enum_distributed = read_methods(distributed_file)
        with open(output_file, 'a', encoding='utf-8') as output:
            for method in methods_distributed:
                if method not in methods_fix:
                    if flag == 0:
                        output.write('\n\t##################################################\n')
                        output.write('\t################## Distributed ###################\n')
                        output.write('\t##################################################\n\n')
                        flag = 1
                    output.write('\t' + method + '\n')
    
        with open(enum_output, 'a', encoding='utf-8') as output:
            output.write('\n\t#################### Distributed #######################\n\n')
            for enum in enum_distributed:
                if enum not in enum_fix:
                    output.write(enum + '\n')
    else:
        print(f"Distributed file {distributed_file} does not exist.")

    # Leer y añadir los métodos de analytics que no están en fix ni en distributed
    flag = 0
    analytics_file = os.path.join(input_folder, 'public_analytics.txt')
    if os.path.exists(analytics_file):
        methods_analytics, enum_analytics = read_methods(analytics_file)
        with open(output_file, 'a', encoding='utf-8') as output:
            for method in methods_analytics:
                if method not in methods_fix and method not in methods_distributed:
                    if flag == 0:
                        output.write('\n\t##################################################\n')
                        output.write('\t#################### Analytics ###################\n')
                        output.write('\t##################################################\n\n')
                        flag = 1
                    output.write('\t' + method + '\n')
    
        with open(enum_output, 'a', encoding='utf-8') as output:
            output.write('\n\t#################### Analytics #######################\n\n')
            for enum in enum_analytics:
                if enum not in enum_fix and enum not in enum_distributed:
                    output.write(enum + '\n')
    else:
        print(f"Analytics file {analytics_file} does not exist.")

    # Leer y añadir los métodos de lite que no están en los anteriores
    flag = 0
    lite_file = os.path.join(input_folder, 'public_lite.txt')
    if os.path.exists(lite_file):
        methods_lite, enum_lite = read_methods(lite_file)
        with open(output_file, 'a', encoding='utf-8') as output:
            for method in methods_lite:
                if method not in methods_fix and method not in methods_distributed and method not in methods_analytics:
                    if flag == 0:
                        output.write('\n\t##################################################\n')
                        output.write('\t###################### Lite ######################\n')
                        output.write('\t##################################################\n\n')
                        flag = 1
                    output.write('\t' + method + '\n')
                    
        with open(enum_output, 'a', encoding='utf-8') as output:
            output.write('\n\t#################### Lite #######################\n\n')
            for enum in enum_lite:
                if enum not in enum_fix and enum not in enum_distributed and enum not in enum_analytics:
                    output.write(enum + '\n')
    else:
        print(f"Lite file {lite_file} does not exist.")
                    
    print(f"Methods extracted and saved in {output_file}")

def unifyEnums():
    input_file = os.path.join(os.getcwd(),'public\\enums.txt')
    output_file = os.path.join(os.getcwd(),'public\\unified_enums.txt')
    methods_file = os.path.join(os.getcwd(), 'public\\extCfgCam_methods.h')
    
    enums = defaultdict(set)

    with open(input_file, 'r') as f:
        text = f.read()

    # Extraer enums del texto
    pattern = re.compile(r'enum (\w+) \{([^}]+)\};')
    matches = pattern.findall(text)
    for enum_name, enum_values in matches:
        values = set(map(str.strip, enum_values.split(',')))
        enums[enum_name].update(values)

    # Escribir enums unificados al archivo de salida
    with open(output_file, 'w') as f:
        for enum_name, values in enums.items():
            f.write(f'\tenum {enum_name} {{ {", ".join(sorted(values))} }};\n')

    print(f'Merged enums written to {output_file}')
    
    with open(methods_file, 'r') as text:
        copy_methods = text.read()
    with open(output_file, 'r') as text:
        copy_enums = text.read()
    with open(methods_file,'w') as text:
        text.write(copy_enums + copy_methods)



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

