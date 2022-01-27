//
//  audioType.h
//  datatypes
//
//  Created by Pete Dowsett on 13/10/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#ifndef audioType_h
#define audioType_h

//typedef double sample_t;

// Sometimes this type definition can even be done conditionally depending on some compile time settings, e.g.:
#define USE_DOUBLE_PRECISION 1
#if USE_DOUBLE_PRECISION
typedef double sample_t;
#else
typedef float sample_t;
#endif


#endif /* audioType_h */
