#ifndef SPRITEPORT_H
#define SPRITEPORT_H
/*
** SpritePort.h
**
** by Samuel D. Crow
*/

#ifndef COPPERVIEW_H
#include <videofx/copperview.h>
#endif /* COPPERVIEW_H */

#ifndef GRAPHICS_BITMAP_H
#include <graphics/bitmap.h>
#endif /* GRAPHICS_BITMAP_H */

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif /* EXEC_NODES_H */

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif /* EXEC_LISTS_H */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

/* VFX_SpritePort structures can be stacked vertically to multiplex sprites */
struct VFX_SpritePort
{
	struct MinNode VFX_SprNode;
	struct BitMap *VFX_bm;
	struct VFX_Coordinate VFX_Position;
	ULONG VFX_SprFlags;
};

struct VFX_SpriteChannel
{
	ULONG VFX_AllocationSize;
	struct MinListHeader VFX_SpritePortList;
};

struct VFX_SpriteTable
{
	/* Maximum number of sprites horizontally */
	UBYTE VFX_MaxSprites;
	UBYTE VFX_SpriteResolution;
	UBYTE VFX_SpriteWidth;
	UBYTE VFX_NumSpriteChannels;
	/* number of VFX_Sprite structs equal to number listed in VFX_NumSprites */
	struct VFX_SpriteChannel VFX_SpriteChannels[];
};


/* Linked sprites limit the number of sprite channels but offer more color. */
/* They also all use the same palette which is useful for horizontalally
 duplicated images across multiple channels. */
#define SB_LINKED 0
#define SF_LINKED 1L<<SB_LINKED
/* Blit mode is recommended any time the sprite images are tall */
/* It's also recommended for vertical doubling or interlace mode. */
#define SB_BLIT 1
#define SF_BLIT 1L<<SB_BLIT
#define SB_INTERLACE 2
#define SF_INTERLACE 1L<<SB_INTERLACE
/* Vertical doubling is mutually exclusive to interlace */
#define SB_VERT_DOUBLE 3
#define SF_VERT_DOUBLE 1L<<SB_VERT_DOUBLE
#define SB_VERT_FLIP 4
#define SF_VERT_FLIP 1L<<SB_VERT_FLIP
/* Horizontal doubling doesn't work in Blit mode */
#define SB_HORIZ_DOUBLE 5
#define SF_HORIZ_DOUBLE 1L<<SB_HORIZ_DOUBLE
/* Horizontal flipping doesn't work in Blit mode */
#define SB_HORIZ_FLIP 6
#define SF_HORIZ_FLIP 1L<<SB_HORIZ_FLIP
#ifdef __SAGA__
#define SB_WRAP 16
#define SF_WRAP 1L<<SB_WRAP
/* 4 bitplane mode on SAGA supercedes linked mode so don't use both */
#define SB_4BITPLANE 17
#define SF_4BITPLANE 1L<<SB_4BITPLANE
#endif

#endif
