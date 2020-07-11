'''
First version only as draft for single example.
'''
import jinja2 as j2 
import math

if __name__ == '__main__':

    env = j2.Environment(
        loader=j2.FileSystemLoader(['./templates', './templates/snippets'])
    )

    env.filters['ceil'] = math.ceil

    buffer_header_template = env.get_template('buffer.h.jinja');
    buffer_code_template = env.get_template('buffer.c.jinja');



    class Buffer:
        name = ''
        n_bytes = 0
        elements = []

        def __init__(self, name, n_bytes):
            self.name = name
            self.n_bytes = n_bytes

    class BufferElement:
        name = ''
        start_bit = 0
        end_bit   = 0

        def __init__(self, name, start_bit, end_bit):
            self.name = name
            self.start_bit = start_bit
            self.end_bit   = end_bit

    buffer = Buffer('examplebuff', 16)
    buffer.elements.append(BufferElement('Doo', 0, 0))
    buffer.elements.append(BufferElement('Moo', 1, 3))

    buffer_header_template.stream(buffer=buffer).dump('../out/{}.h'.format(buffer.name))
    buffer_code_template.stream(buffer=buffer).dump('../out/{}.c'.format(buffer.name))

