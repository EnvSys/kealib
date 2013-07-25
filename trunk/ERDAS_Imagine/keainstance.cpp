/*
 *  keainstance.cpp
 *  LibKEA
 *
 *  Created by Sam Gillingham on 26/07/2013.
 *  Copyright 2013 LibKEA. All rights reserved.
 *
 *  This file is part of LibKEA.
 *
 *  Permission is hereby granted, free of charge, to any person 
 *  obtaining a copy of this software and associated documentation 
 *  files (the "Software"), to deal in the Software without restriction, 
 *  including without limitation the rights to use, copy, modify, 
 *  merge, publish, distribute, sublicense, and/or sell copies of the 
 *  Software, and to permit persons to whom the Software is furnished 
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be 
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR 
 *  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
 *  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION 
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
/*
********************************************************************************
Support for KEA file format within Imagine
********************************************************************************
*/

#include "kea.h"

long
keaInstanceTitleListGet(unsigned long *count, char ***titleList )
{
#ifdef DEBUG
    fprintf( stderr, "%s\n", __FUNCTION__ );
#endif
    *titleList = emsc_New(1, char * );
    (*titleList)[0] = estr_Duplicate((char*)"KEA File Format");
    *count = 1;

	return 0;
}

long
keaInstanceTemplateListGet(char ***templateList, char **templateListPseudoFlags)
{
#ifdef DEBUG
    fprintf( stderr, "%s\n", __FUNCTION__ );
#endif
    *templateList = emsc_New(1, char * );
    (*templateList)[0] = estr_Duplicate((char*)"*.kea");

	/*
	** None of these extensions are pseudo extensions, so we do not
	** need to set any flags
	*/
	*templateListPseudoFlags = (char*)NULL;

	return 0;
}

long
keaInstanceExtListGet(char ***extList)
{
#ifdef DEBUG
    fprintf( stderr, "%s\n", __FUNCTION__ );
#endif
    *extList = emsc_New(1, char * );
    (*extList)[0] = estr_Duplicate((char*)".kea");

	return 0;
}

long
keaInstanceShortNameListGet(char ***shortNameList)
{
#ifdef DEBUG
    fprintf( stderr, "%s\n", __FUNCTION__ );
#endif
    *shortNameList = emsc_New(1, char * );
    (*shortNameList)[0] = estr_Duplicate((char*)"kea");

	return 0;
}

long
keaInstanceFilterFlagsGet( char **flags )
{
#ifdef DEBUG
    fprintf( stderr, "%s\n", __FUNCTION__ );
#endif
    *flags = emsc_New(1, char);
    (*flags)[0] = 1;
    return 0;
}

long
keaInstanceIsDirFlagsGet( char **flags )
{
#ifdef DEBUG
    fprintf( stderr, "%s\n", __FUNCTION__ );
#endif
    *flags = emsc_New(1, char);
    (*flags)[0] = 0;
    return 0;
}

long
keaInstancePixelTypesGet(unsigned long *count, char  ***pixelTypes)
{
#ifdef DEBUG
    fprintf(stderr, "%s\n", __FUNCTION__ );
#endif

    // just make a list where the indices match the KEADataType enum
    // because the first one is 'undefined' just pad it with something
    // we are in trouble if the enum ever changes...
    // also do the same for kea_64int and kea_64uint
    *count = kealib::kea_64float + 1;
    *pixelTypes = emsc_New(kealib::kea_64float + 1, char *);
    (*pixelTypes)[0] = estr_Duplicate((char*)"s8"); // kea_undefined
    (*pixelTypes)[1] = estr_Duplicate((char*)"s8"); // kea_8int
    (*pixelTypes)[2] = estr_Duplicate((char*)"s16"); // kea_16int
    (*pixelTypes)[3] = estr_Duplicate((char*)"s32"); // kea_32int
    (*pixelTypes)[4] = estr_Duplicate((char*)"s32"); // kea_64int - not supported
    (*pixelTypes)[5] = estr_Duplicate((char*)"u8"); // kea_8uint
    (*pixelTypes)[6] = estr_Duplicate((char*)"u16"); // kea_16uint
    (*pixelTypes)[7] = estr_Duplicate((char*)"u32"); // kea_32uint
    (*pixelTypes)[8] = estr_Duplicate((char*)"u32"); // kea_64uint - not supported
    (*pixelTypes)[9] = estr_Duplicate((char*)"f32"); //  kea_32float
    (*pixelTypes)[10] = estr_Duplicate((char*)"f64"); // kea_64float

    return 0;
}

long
keaInstanceCompressionTypesGet(unsigned long *count, char  ***compressionTypes)
{
#ifdef DEBUG
    fprintf(stderr, "%s\n", __FUNCTION__ );
#endif
    // we just support one type - zlib. Note that this is just for display
    // data is expected to be uncompressed by the time Imagine sees it
    *count = 1;
    *compressionTypes = emsc_New(1, char *);
    (*compressionTypes)[0] = estr_Duplicate((char*)"zlib");

    return 0;
}

long
keaInstanceLayerTypesGet( unsigned long  *count,  char  ***layerTypes)
{
#ifdef DEBUG
    fprintf(stderr, "%s\n", __FUNCTION__ );
#endif
    // make it match the KEALayerType enum
    *count = 2;
    *layerTypes = emsc_New(2, char *);
    (*layerTypes)[0] = estr_Duplicate((char*)"athematic");
    (*layerTypes)[1] = estr_Duplicate((char*)"thematic");

    return 0;
}

long
keaInstanceColumnTypesGet(unsigned long *count, char ***columnTypes)
{
#ifdef DEBUG
    fprintf(stderr, "%s\n", __FUNCTION__ );
#endif
    // make it match KEAFieldDataType enum
    *count = kealib::kea_att_string + 1;
    *columnTypes = emsc_New(kealib::kea_att_string + 1, char *);
    (*columnTypes)[0] = estr_Duplicate((char*)"integer"); // kea_att_na
    (*columnTypes)[1] = estr_Duplicate((char*)"integer"); // kea_att_bool - treat as int
    (*columnTypes)[2] = estr_Duplicate((char*)"integer"); // kea_att_int
    (*columnTypes)[3] = estr_Duplicate((char*)"real"); // kea_att_float
    (*columnTypes)[4] = estr_Duplicate((char*)"string"); // kea_att_string

    return 0;
}

