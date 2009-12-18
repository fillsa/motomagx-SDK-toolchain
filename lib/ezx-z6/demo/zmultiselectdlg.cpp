#include <ZApplication.h>
#include <ZMultiSelectDlg.h>
#include <ZListBox.h>

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <qtextcodec.h>

static void usage(char * prog)
{
    fprintf(stderr, "Usage: %s [ -H HEADER_TEXT ] [ -t #TIMEOUT ] "
	            "ITEM1_TEXT ITEM2_TEXT ...\n",
	    prog);
    exit(-1);
}

int main( int argc, char **argv )
{
	ZApplication* a = new ZApplication( argc, argv );
	QString head("Header");
	QString msg("What?");
	QStringList list;
	bool is_checked[1024];
	int timeout = 0;

	memset(is_checked, 0, sizeof(is_checked));

	int ch;
	while ((ch = getopt(argc, argv, "H:M:S:t:")) != EOF) {
	    switch (ch) {
	    case 'H':
		head = QString::fromUtf8(optarg);
		break;
	    case 'M':
		msg = QString::fromUtf8(optarg);
		break;
	    case 't':
		timeout = atoi(optarg);
		break;
	    default:
		usage(argv[0]);
	    }
	}

	argc -= optind;
	argv += optind;

	int count = 0;

	while (argc > 0) {
	    char * str = argv[0];
	    if (str[0] == '+') {
		str++;
		if (count < 1024)
		    is_checked[count] = true;
	    }
	    list += QString::fromUtf8(str);
	    argc--; argv++; count++;
	}

	ZMultiSelectDlg* dlg = new ZMultiSelectDlg(head, msg, NULL,
						   "ZMultiSelectDlg", true,
						   0, 0);
	dlg->addItemsList(list);

	ZListBox* listbox = dlg->getListBox();

	for (int i = 0; i < count; i++)	{
	    if (is_checked[i])
		listbox->checkItem(i, true);
	}

	if (timeout)
	    dlg->setAutoDismissTime(timeout*1000);

   	a->setMainWidget(dlg);
    	dlg->show();
   	a->exec();

	int result = dlg->result();
	if (result != 1) {
		result = 0;
	} else {
	    for (int i = 0; i < count; i++) {
		if (listbox->itemChecked(i))
		    printf( "%d\n", i);
	    }
	    result = dlg->getCheckedItemCount();
	}
	return result;
}
