# bitter
# buffer

## Limitations
- Buffer must be 4 Byte aligned. That means the buffer size will be either of 32 bit, 64 bit, 96 bit, 128 bit ...
- Only UInt32 values are allowed as of now. Support for UInt8, UInt16 and Boolean types would be next on the list.
- As of now, all values must start at 0 .. MAX. Support for arbitrary ranges MIN .. MAX might come in the future.
- Endianness is not set yet.


Uses information from:
https://stackoverflow.com/questions/11815894/how-to-read-write-arbitrary-bits-in-c-c 
