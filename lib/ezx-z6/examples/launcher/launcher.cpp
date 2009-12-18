#include <ZApplication.h>
#include <ZSingleSelectDlg.h>
#include <ZListBox.h>

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	ZApplication* a = new ZApplication(argc, argv);
	QStringList list;
	DIR *d;
	struct dirent *de;
	char * cmd[1024];
	int count = 0;

	d = opendir("/mmc/mmca1/scripts");
	if (d == NULL)
	    exit(1);

	while ((de = readdir(d)) != NULL) {
	    if (de->d_name[0] == '.')
		continue;
	    if (count >= 1024)
		break;
	    list += QString::fromUtf8(de->d_name);
	    cmd[count] = strdup(de->d_name);
	    count++;
	}

	ZSingleSelectDlg* dlg = new ZSingleSelectDlg(QString("Launcher"),
						     QString("Select command"),
						     NULL,
						   "ZSingleSelectDlg", true,
						   0, 0);

	dlg->addItemsList(list);

   	a->setMainWidget(dlg);
    	dlg->show();
   	a->exec();

	int result = dlg->result();
	if (result != 1) {
	    result = 0;
	} else {
		result = dlg->getCheckedItemIndex();
		delete dlg;
		delete a;

		if (result < count) {
		    char buf[128 + strlen(cmd[result])];
		    sprintf(buf, "/mmc/mmca1/scripts/%s", cmd[result]);
		    system(buf);
		}
	}
	return 0;
}
