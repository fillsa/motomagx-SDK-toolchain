#! /bin/bash

# This file is in KOI8-R. When copying to handset, it should
# be converted to UTF8:
#    iconv -f koi8-r -t utf-8 test.sh > /z6/mmc/mmca1/tests/test.sh

cd /mmc/mmca1/tests/

echo znoticedlg.cpp

./znoticedlg -H "��������� ZNoticeDlg, #1" -t 10 \
             -S notice \
             "����� ������"

echo Exit code $?

./znoticedlg -H "��������� ZNoticeDlg, #2" -t 10 \
             -S exclamation \
             "����� ������"

echo Exit code $?

./znoticedlg -H "��������� ZNoticeDlg, #3" \
             -S nothing -t 5 \
             -M "������ �� �����" "����� 5 sec"

echo Exit code $?

echo zmessagedlg.cpp

./zmessagedlg -H "��������� ZMessageDlg, #1" \
             -S ok_cancel \
             "����� ������ OK"

echo Exit code $?

./zmessagedlg -H "��������� ZMessageDlg, #2" \
             -S yes_no \
             "����� ������ NO"

echo Exit code $?

./zmessagedlg -H "��������� ZMessageDlg, #3" \
             -S ok -t 5 \
             "������ �� �����" "����� 5 c��"

echo Exit code $?

echo znumpickerdlg.cpp

./znumpickerdlg -H "��������� ZNumPickerDlg #1" \
              -V 20 -m 0 -M 100 -L "33!" "�������� 33"

echo Exit code $?

./znumpickerdlg -H "��������� ZNumPickerDlg #2" -t 5 \
                 -V 10 -m 0 -M 100 -L "�� �������� ������" "����� 5 sec..." 

echo Exit code $?


echo zsinglecapturedlg.cpp

./zsinglecapturedlg -H "��������� ZSingleCaptureDlg #1" \
                    -S normal "�������� ���-������"

echo Exit code $?

echo zsingleselectdlg.cpp

./zsingleselectdlg -H "��������� ZSingleSelectDlg #1" \
                       -M "�������� ����" \
                       "�����" "������" "������" "���"

echo Exit code $?

./zsingleselectdlg -H "��������� ZSingleSelectDlg #2" -t 5 \
                       -M "�� �������, ���� 5 sec" \
                       "�����" "������" "������" "+���"

echo Exit code $?

echo zmultiselectdlg.cpp

./zmultiselectdlg -H "��������� ZMultiSelectDlg #1" \
                       -M "�������� ������" \
                       "������" "+������" "+�����" "+���" "�����"

echo Exit code $?

./zmultiselectdlg -H "��������� ZMultiSelectDlg #2" -t 5 \
                       -M "������ ������ �� ����, ������ ����� 5 ���" \
                       "������" "+������" "+�����" "+���" "�����"

echo Exit code $?

