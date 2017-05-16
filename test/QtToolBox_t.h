#ifndef QTTOOLBOX_T_H
#define QTTOOLBOX_T_H


#include <QToolBox>
#include <QGroupBox>
#include <QLabel>
#include <QHBoxLayout>

class ToolBox : public QToolBox
{
	Q_OBJECT

public:
	ToolBox(QWidget *parent = 0)
		: QToolBox(parent)
	{
		initUI();

		// �����źŲ�
		connect(this, &QToolBox::currentChanged, this, &ToolBox::onCurrentChanged);
	}

private:
	void initUI() {
		struct User {
			bool bVIP;  // ��Ա
			QString strName;  // ����
			QString strIcon;  // ͼ��
			QString strDesc;  // ����˵��
		} user[3][5] =
		{
			{
				{true, QStringLiteral("���㹫��"), ":/QQ/1", QStringLiteral("��ӹ���µĵ�һ��Ů")},
				{true, QStringLiteral("С��Ů"), ":/QQ/2", QStringLiteral("��Ů�ľ�")},
				{true, QStringLiteral("������"), ":/QQ/3", QStringLiteral("���������ѧ����")},
				{false, QStringLiteral("����"), ":/QQ/4", QStringLiteral("��Ԫ��һ����")},
				{false, QStringLiteral("������"), ":/QQ/5", QStringLiteral("�⸴���Һ�ɽ��������")}
			},

			{
				{true, QStringLiteral("����"), ":/QQ/6", QStringLiteral("ؤ����� - ����˫ȫ�����Թ��ˡ������ˬ")},
				{true, QStringLiteral("�����"), ":/QQ/8", QStringLiteral("���¾Ž�")},
				{true, QStringLiteral("���"), ":/QQ/9", QStringLiteral("��Ȼ������")},
				{false, QStringLiteral("����"), ":/QQ/7", QStringLiteral("����ʮ����")},
				{false, QStringLiteral("��һ��"), ":/QQ/10", QStringLiteral("�ɶ�����")}
			},

			{
				{true, QStringLiteral("���ַ���"), ":/QQ/11", QStringLiteral("���������")},
				{true, QStringLiteral("������"), ":/QQ/13", QStringLiteral("�������ɣ������ޱ�")},
				{false, QStringLiteral("��ǧ��"), ":/QQ/12", QStringLiteral("����ˮ��Ʈ")},
				{false, QStringLiteral("����"), ":/QQ/14", QStringLiteral("��Ԫ������")},
				{false, QStringLiteral("��Ī��"), ":/QQ/15", QStringLiteral("�������룬ɱ������")}
			}
		};

		QStringList groupList;
		groupList << QStringLiteral("����Ů") << QStringLiteral("��Ӣ��") << QStringLiteral("�����");

		// ��ʼ���б�
		for (int i = 0; i < sizeof(user)/sizeof(user[0]); i++)
		{
			QGroupBox *pGroupBox = new QGroupBox(this);
			QVBoxLayout *pLayout = new QVBoxLayout(pGroupBox);

			// ��Ӻ���
			for (int j = 0; j < sizeof(user[0])/sizeof(user[0][0]); ++j)
			{
				QWidget *pWidget = initWidget(user[i][j].bVIP, user[i][j].strName,
					user[i][j].strIcon, user[i][j].strDesc);
				pLayout->addWidget(pWidget);
			}
			pLayout->addStretch();
			pLayout->setSpacing(10);
			pLayout->setContentsMargins(10, 10, 10, 10);

			// ��ӷ���
			addItem(pGroupBox, groupList.at(i));
		}
	}

	QWidget* initWidget(bool bVIP, const QString &name,
		const QString &icon, const QString &desc = "") {
			QWidget *pWidget = new QWidget(this);
			QLabel *pPixmapLabel = new QLabel(this);
			QLabel *pNameLabel = new QLabel(this);
			QLabel *pDescLabel = new QLabel(this);

			// ͼ�� ���� ����
			pPixmapLabel->setPixmap(QPixmap(icon));
			pNameLabel->setText(name);
			pDescLabel->setText(desc);

			// VIP����Ϊ��ɫ�����򣬰�ɫ
			pNameLabel->setStyleSheet(QString("color: %1;").arg(bVIP ? "rgb(240, 30, 40)" : "white"));
			pDescLabel->setStyleSheet("color: gray;");

			QVBoxLayout *pVLayout = new QVBoxLayout();
			pVLayout->addStretch();
			pVLayout->addWidget(pNameLabel);
			pVLayout->addWidget(pDescLabel);
			pVLayout->addStretch();
			pVLayout->setSpacing(5);
			pVLayout->setContentsMargins(0, 0, 0, 0);

			QHBoxLayout *pHLayout = new QHBoxLayout();
			pHLayout->addWidget(pPixmapLabel);
			pHLayout->addLayout(pVLayout);
			pHLayout->addStretch();
			pHLayout->setContentsMargins(0, 0, 0, 0);

			pWidget->setLayout(pHLayout);

			return pWidget;
	}

	private slots:
		void onCurrentChanged(int index) {
			QString strGroup = itemText(index);
			qDebug() << strGroup;
		}
};


















#endif