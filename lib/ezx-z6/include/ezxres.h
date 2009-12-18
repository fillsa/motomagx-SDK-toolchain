/*
 * Unofficial EZX Native Software Development Kit
 * Copyright (C) 2005 Sam Revitch <samr7@cs.washington.edu>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * Further, this software is distributed without any warranty that it is
 * free of the rightful claim of any third person regarding infringement
 * or the like.  Any license provided herein, whether implied or
 * otherwise, applies only to this software file.  Patent licenses, if
 * any, provided herein do not apply to combinations of this program with
 * other software, or any other product whatsoever.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#if !defined(__EZX_RES_H__)
#define __EZX_RES_H__

#include <qpixmap.h>
#include <qimage.h>
#include <qmovie.h>
#include <qbitmap.h>

/*
 * Below are resource names that have been identified by
 * trolling through some apps.
 */

#define RES_ICON_DLG_EMPTY_TRASH	"Dialog_Empty_Trash.gif"
#define RES_ICON_DLG_EXCLAMATORY_MARK	"Dialog_Exclamatory_Mark.gif"
#define RES_ICON_DLG_WAITING		"Dialog_Waiting.gif"
#define RES_ICON_DLG_ERROR		"Dialog_Error.gif"
#define RES_ICON_DLG_COMPLETE		"Dialog_Complete.gif"


class UTIL_Skin;

class RES_ICON_Reader {
public:
	RES_ICON_Reader();
	~RES_ICON_Reader();
	
	QPixmap getIcon(const char *imageFileName, bool hasRet = TRUE);
    QPixmap getIcon(const char *imageFileName, int height, int width);
	QMovie getMovie(QString const& imageFileName);
private:	
	static UTIL_Skin *pReader;
};

#endif
