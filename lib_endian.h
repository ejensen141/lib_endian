/*Copyright (c) 2015 Elijah Jensen

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software/hardware and associated documentation files 
(the "Software" or "Hardware" design plans), to deal in the Software/Hardware 
without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies 
or substantial portions of the Software/Hardware.

THE SOFTWARE/HARDWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name(s) of the above copyright holders shall 
not be used in advertising or otherwise to promote the sale, use or other dealings 
in this Software without prior written authorization.
*/
// endianness
#ifndef _LIB_ENDIAN_H
#define _LIB_ENDIAN_H





//#define endian_8BIT_enable
//#define endian_16BIT_enable
#define endian_32BIT_enable
//#define endian_64BIT_enable


#ifdef endian_32BIT_enable
uint32_t read_little_endian(uint8_t *buffer, uint8_t num)
{
        // this function reads a little_endian number of bytes into a 32bit word... the max number of bytes that can be read is 4

        if(num <=4)
        {
        uint32_t data_out =0;

        for(uint8_t i =0; i<num; i++)
        {
                data_out |= (buffer[i]<<i*8);
        }

        return data_out;
        }
        else
        { return 0;}
}

uint32_t read_big_endian(uint8_t *buffer, uint8_t num)
{
        // this function reads a big endian number of bytes into a 32bit word
        if(num<=4)
        {
        uint32_t data_out = 0;
        uint8_t start = num-1;

        int i = num-1;
        do{
                data_out |=  (buffer[i]<<8*(3-i));
        i=i-1;
        }while(i>0);



        return data_out;
        }

        else
        {return 0;}

}

#endif


#endif
