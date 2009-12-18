/****************************************************************************
 ** $Id:  qt/qlibrary.h	  3.0.0	  edited Sep 20 19:46 $
 **
 ** Definition of QLibrary class
 **
 ** Created : 2000-01-01
 **
 ** Copyright (C) 2000 Trolltech AS.  All rights reserved.
 **
 ** This file is part of the kernel module of the Qt GUI Toolkit.
 **
 ** This file may be distributed under the terms of the Q Public License
 ** as defined by Trolltech AS of Norway and appearing in the file
 ** LICENSE.QPL included in the packaging of this file.
 **
 ** This file may be distributed and/or modified under the terms of the
 ** GNU General Public License version 2 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.GPL included in the
 ** packaging of this file.
 **
 ** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
 ** licenses may use this file in accordance with the Qt Commercial License
 ** Agreement provided with the Software.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
 **	  information about Qt Commercial License Agreements.
 ** See http://www.trolltech.com/qpl/ for QPL licensing information.
 ** See http://www.trolltech.com/gpl/ for GPL licensing information.
 **
 ** Contact info@trolltech.com if any conditions of this licensing are
 ** not clear to you.
 **
 **	Modified by BJDC, Motorola 
 **
 **********************************************************************/

#ifndef QLIBRARY_H
#define QLIBRARY_H

#ifndef QT_H
#include <qstring.h>
#endif // QT_H

#ifndef QT_NO_COMPONENT

#include "qcom.h"
//#include "quuid.h"

class QLibraryPrivate;

/**
 * The QLibrary class provides a wrapper for handling shared libraries.
 *
 * An instance of a QLibrary object can handle a single shared library and
 * provide access to the functionality in the library in a platform independent way.
 * If the library is a component server, QLibrary provides access to the exported
 * component and can directly query this component for interfaces.
 *
 * QLibrary ensures that the shared library is loaded and stays in memory whilst it is
 * in use. QLibrary can also unload the library on destruction and release unused resources.
 *
 * A typical use of QLibrary is to resolve an exported symbol in a shared object, and to
 * call the function that this symbol represents. This is called "explicit linking"
 * in contrast to "implicit linking", which is done by the link step in the build process
 * when linking an executable against a library.
 *
 * The following code snippet loads a library, resolves the symbol "mysymbol", and calls
 * the function if everything succeeded. If something went wrong, e.g. the library file
 * does not exist or the symbol is not defined, the function pointer will be 0 and won't
 * be called. When the QLibrary object is destroyed the library will be unloaded, making
 * all references to memory allocated in the library invalid.
 *
 * @code
 * typedef void (*MyPrototype)();
 * MyPrototype myFunction;
 *
 * QLibrary myLib( "mylib" );
 * myFunction = (MyProtoype) myLib.resolve( "mysymbol" );
 * if ( myFunction )
 * {
 *	  myFunction();
 * }
 * @endcode
 */

class Q_EXPORT QLibrary
{
public:
	
	/**
	 * Constructor of QLibrary
	 *
	 * Creates a QLibrary object for the shared library filename. The library will be
	 * unloaded in the destructor.
	 *
	 * @see load(), unload(), and setAutoUnload().
	 *
	 * @note that filename does not need to include the (platform specific) file extension,
	 * so calling:
	 *		QLibrary lib( "mylib" );
	 * is equivalent to calling:
	 *		QLibrary lib( "mylib.dll" );
	 *
	 * If filename does not include a path, the library loader will look for the file in
	 * the platform specific search paths.
	 */
	QLibrary( const QString& filename );

	/**
	 * Deletes the QLibrary object.
	 *
	 * The library will be unloaded if autoUnload() is TRUE (the default),
	 * otherwise it stays in memory until the application exits.
	 *
	 * @see unload() and setAutoUnload().
	 */
	virtual ~QLibrary();

	/**
	 * Returns the address of the exported symbol symb. The library is loaded if
	 * necessary. The function returns 0 if the symbol could not be resolved or
	 * the library could not be loaded.
	 *
	 *@code
	 * typedef int (*avgProc)( int, int );
	 *
	 * avgProc avg = (avgProc) library->resolve( "avg" );
	 * if ( avg )
	 * {
	 *	   return avg( 5, 8 );
	 * }
	 * else
	 * {
	 *	   return -1;
	 *	}
	 * @endcode
	 *
	 */
	void *resolve( const char* );

	/**
	 * This is an overloaded member function, provided for convenience.
	 * It behaves essentially like the above function.
	 * Loads the library filename and returns the address of the exported symbol symb.
	 *
	 * The function returns 0 if the symbol could not be resolved or the library
	 * could not be loaded.

	 * This function is useful only if you want to resolve a single symbol,
	 * e.g. a function pointer from a specific library once:

	 *@code
	 * typedef void (*FunctionType)();
	 * static FunctionType *ptrFunction = 0;
	 * static bool triedResolve = FALSE;
	 * if ( !ptrFunction && !triedResolve )
	 *	   ptrFunction = QLibrary::resolve( "mylib", "mysymb" );
	 *
	 * if ( ptrFunction )
	 *		ptrFunction();
	 * else
	 *	  ...
	 * @endcode
	 *	  
	 * @note that like the constructor, filename does not need to include the (platform
	 * specific) file extension. The library remains loaded until the process exits.
     */
	static void *resolve( const QString &filename, const char * );

	/**
	 * Loads the library. Since resolve() always calls this function before
	 * resolving any symbols it is not necessary to call it explicitly. In
	 * some situations you might want the library loaded in advance, in which
	 * case you would use this function.
	 */
	bool load();

	/**
	 * Unloads the library and returns TRUE if the library could be unloaded;
	 * otherwise returns FALSE.

	 * This function is called by the destructor if autoUnload() is enabled.
	 */
	virtual bool unload();

	/**
	 * Returns TRUE if the library is loaded; otherwise returns FALSE.
	 *
	 * @see unload().
	 */
	bool isLoaded() const;

	/**
	 * Returns TRUE if the library will be automatically unloaded when
	 * this wrapper object is destructed; otherwise returns FALSE.
	 * The default is TRUE.
	 */
	bool autoUnload() const;

	/**
	 * If enabled is TRUE (the default), the wrapper object is set to automatically
	 * unload the library upon destruction. If enabled is FALSE, the wrapper object
	 * is not unloaded unless you explicitly call unload().
	 */
	void setAutoUnload( bool enable );

	/**
	 * Returns the filename of the shared library this QLibrary object handles,
	 * including the platform specific file extension.
	 *
	 *@code
	 * QLibrary lib( "mylib" );
	 * //set str to	 "libmylib.so"
	 * QString str = lib.library();
	 * @endcode
	 */
	QString library() const;

	/**
	 * Forwards the query to the component and returns the result. request and
	 * iface are propagated to the component's queryInterface implementation.
	 *
	 * The library gets loaded if necessary.
     */
	QRESULT queryInterface( const QUuid& request, QUnknownInterface** iface);
	

private:
	
	void createInstance();

private:
	
	QUnknownInterface *entry;
	QLibraryPrivate *d;
	QString libfile;
	uint aunload : 1;

#if defined(Q_DISABLE_COPY)
private:  // Disabled copy constructor and operator=
	
	QLibrary( const QLibrary & );
	QLibrary &operator=( const QLibrary & );
#endif
};

#endif //QT_NO_COMPONENT

#endif //QLIBRARY_H
