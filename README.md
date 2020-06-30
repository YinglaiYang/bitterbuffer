# bitterbuffer
[![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://lbesson.mit-license.org/)

ANSI C99, paddingless, flat, bit-level serializer/deserializer.

## Limitations
- Buffer must be 4 Byte aligned. That means the buffer size will be either of 32 bit, 64 bit, 96 bit, 128 bit ...
- Only UInt32 values are allowed as of now. Support for UInt8, UInt16 and Boolean types would be next on the list.
- No values with more than 32 bits supported. Very low priority to expand to larger types.
- As of now, all values must start at 0 .. MAX. Support for arbitrary ranges MIN .. MAX might come in the future.
- Endianness is not set yet.

## Roadmap
1. Definition of bitterbuffer schema format based on YAML.
2. Definition of code for intra-block processing (fields that are split over two )
3. Python based generator of C-code with Jinja2 and templates.
4. Documentation with examples.
5. Addition of schema sanity in Generator.
6. Addition of error-catching in generated code.
7. Research possibilities for optimization.


Uses information from:
https://stackoverflow.com/questions/11815894/how-to-read-write-arbitrary-bits-in-c-c 
