#ifndef XDATA_H
#define XDATA_H

#include <QString>
#include <functional>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "XLogManagement.h"
#include "XObjectManagement.h"

namespace XData
{
#define VS(x) static inline QString x = #x
#define VC(x) static inline const char* x = #x
#define ClassName(value) static inline QString className = value

    static QSqlDatabase db;

	struct Windows
	{
		enum
		{
			WN_LOADING,
			WN_STARTUP,
			WN_APP
		};
	};

    struct Forms
    {
        enum
		{
        };
    };

    //==============================================================================
    struct PageParent
    {
        VC(close);
        VC(open);
    };

    struct obj_page_example : PageParent
    {
        ClassName("obj_page_example");

        VS(setData);
    };

}

#endif // XDATA_H
