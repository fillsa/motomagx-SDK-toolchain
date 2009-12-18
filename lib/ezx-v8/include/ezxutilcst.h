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

#if !defined(__EZX_UTIL_CST_H__)
#define __EZX_UTIL_CST_H__
#include <zpushbutton.h>

/*
 * This is some sort of utility widget for the lower toolbar.
 */

#define EZX_CST_BTN_MENU QString("CST_Menu")
#define EZX_CST_BTN_EXIT QString("CST_Exit")

class UTIL_CST : public QWidget {
	Q_OBJECT
public:
	UTIL_CST(QWidget *mainWidget,
		 QString middleButton,
		 QString leftButton  = EZX_CST_BTN_MENU,
		 QString rightButton = EZX_CST_BTN_EXIT);
	virtual ~UTIL_CST();

    void blockSignals(bool);
    bool getQuickExit();
    void setQuickExit(bool);

    ZPushButton *getLeftBtn(void);
    ZPushButton *getMidBtn(void);
    ZPushButton *getRightBtn(void);

private:
	ZPushButton 	*m_btn_b8;
	ZPushButton 	*m_btn_bc;
	ZPushButton 	*m_btn_c0;
	bool 		     m_i_c4;
};

#endif  /* !defined(__EZX_UTIL_CST_H__) */
