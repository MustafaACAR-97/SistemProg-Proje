#ifndef	_HELPER_H_
#define	_HELPER_H_

#include "jrb.h"
#include "fields.h"

typedef struct partInfo
{
  char kelime[30];
  char huffmankodu[30];
  char *(*virtualFonksiyon)(void *, int);
  char *(*overWriteFonksiyonu)(void *, int);
} Part;

typedef struct nesne
{
  Part satirIcerigi[506];
} Nesne;

extern void *kilitIcerigi(int, void *, void *);
extern char *valuesi(Nesne *, int);
extern char *huffmani(Nesne *, int);
extern void dosyaOlustur(char *);
extern void dosyayaYaz(char *, char *);
extern void sifrele(char **, JRB);
extern void sifreCoz(char **, JRB);
extern void oku(char **, JRB);


#define NEW(objname) (struct objname *)NEW_##objname()
#define NEW_nesne() kilitIcerigi(sizeof(struct nesne), valuesi, huffmani)

#endif