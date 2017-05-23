#include "sy_1.h"
#include "Pyramid_Class.h"
#include <comutil.h>
#include <direct.h>  
#include <io.h>  
#include <Windows.h>  


//******�����������Լ���������ļ�·����ȫ�ֱ���*****///
vector<IplImage*>img;


//char* path[20];//��һ��·��Ϊ�ļ���·��
//const char * InfilePath1, * InfilePath2; ///�ļ�������·��
/*const char * InPath1, * InPath2;*///, * resultfile;  ///�ļ���·��
string reFile_path,senFile_path;////�ο�ͼ��ʹ���׼ͼ�������ļ��е�·��
string reImage_full,senImage_full;///�ο�ͼ��ʹ���׼ͼ������·��

string resultImage_path;
vector<string> simage_repath;
vector<string> simage_senpath;///�ֱ𱣴����ڳ���ƥ���Сͼ��·��
vector<string> ResultImagePath;
vector<CvPoint2D64f> rePoint;
vector<CvPoint2D64f> senPoint;

//const char * simage_repath[10], * simage_senpath[10]; //�������ڳ���ƥ���Сͼ��·��

//string simage_repath,simage_senpath; ///�ֱ𱣴����ڳ���ƥ���Сͼ��·��
//
////������������ȫ�ֱ�����Ҳ�����������ݼ���Ҫ�����г��򶼹ر��Ժ�Ż��ͷţ���˻���ּ�ʹͼ�񱣴���Ҳû�취���õ����
//PyramidBase pyramid1; ////����취����ʹ�������඼�Ǿֲ�������������ȫ�ֵ�
//PyramidBase pyramid2;



////****surf�㷨���õ���ȫ�ֱ���*****////
int num1;
int num2;
//double mese1;	///����
double mese2;//��ͼ��׼����

double t2;
double t3;


vector<CvMat*> H_1;///��ʱû���õ�
vector<CvMat*> H_2;///���Դ洢H����

CvSeq* objectKeypoints = 0, * objeceDescriptors = 0;  ///����ͼ��������㼰������Ϣ
CvSeq* imageKeypoints = 0, * imageDescriptors = 0;

vector<int> ptpairs_befores; //�洢��ѡ֮ǰ��ƥ����������
//vector<int> ptpairs_afters; // ������ѡ֮���ƥ����������



sy_1::sy_1(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	
	ui.setupUi(this);

	//Map�ؼ�����
	ui.MapCtr1->setControl("{C552EA94-6FBB-11d5-A9C1-00104BB6FC1C}");
	ui.MapToolBarCtr1->setControl("{B7D4358E-3CBC-11D6-AA09-00104BB6FC1C}");
	ui.MapCtr2->setControl("{C552EA94-6FBB-11d5-A9C1-00104BB6FC1C}");
	ui.MapToolBarCtr2->setControl("{B7D4358E-3CBC-11D6-AA09-00104BB6FC1C}");
//	ui.MapCtr3->setControl("{C552EA94-6FBB-11d5-A9C1-00104BB6FC1C}");
//	ui.MapToolBarCtr3->setControl("{B7D4358E-3CBC-11D6-AA09-00104BB6FC1C}");
	ui.MapCtr4->setControl("{C552EA94-6FBB-11d5-A9C1-00104BB6FC1C}");
	ui.MapToolBarCtr4->setControl("{B7D4358E-3CBC-11D6-AA09-00104BB6FC1C}");

	ui.MapTocCtr1->setControl("{A0F9A9A2-4A3F-4888-826F-CA2BFA23CF17}");
	ui.MapTocCtr2->setControl("{A0F9A9A2-4A3F-4888-826F-CA2BFA23CF17}");

	


	//��ui����Ŀؼ��Ͷ����ָ�����
	//Map�ؼ�
	ui.MapToolBarCtr1->queryInterface(QUuid(IID_IToolbarControl),(void**)&m_pToolbarControl1);
	ui.MapCtr1->queryInterface(QUuid(IID_IMapControl3),(void**)&m_pMapControl1);
	ui.MapToolBarCtr2->queryInterface(QUuid(IID_IToolbarControl),(void**)&m_pToolbarControl2);
	ui.MapCtr2->queryInterface(QUuid(IID_IMapControl3),(void**)&m_pMapControl2);
//	ui.MapToolBarCtr3->queryInterface(QUuid(IID_IToolbarControl),(void**)&m_pToolbarControl3);
//	ui.MapCtr3->queryInterface(QUuid(IID_IMapControl3),(void**)&m_pMapControl3);
	ui.MapToolBarCtr4->queryInterface(QUuid(IID_IToolbarControl),(void**)&m_pToolbarControl4);
	ui.MapCtr4->queryInterface(QUuid(IID_IMapControl3),(void**)&m_pMapControl4);


	ui.MapTocCtr1->queryInterface(QUuid(IID_ITOCControl),(void**)&m_pTOCControl1);
	ui.MapTocCtr2->queryInterface(QUuid(IID_ITOCControl),(void**)&m_pTOCControl2);

	//���������Ϳؼ������
	//Map�ؼ�
	m_pToolbarControl1->SetBuddyControl(m_pMapControl1);
	m_pToolbarControl2->SetBuddyControl(m_pMapControl2);
//	m_pToolbarControl3->SetBuddyControl(m_pMapControl3);
	m_pToolbarControl4->SetBuddyControl(m_pMapControl4);

	m_pTOCControl1->SetBuddyControl(m_pMapControl1);
	m_pTOCControl2->SetBuddyControl(m_pMapControl2);

	//�������ӹ���������

	AddMapToolBarCtr(m_pToolbarControl1);//map
	AddMapToolBarCtr(m_pToolbarControl2);//map
//	AddMapToolBarCtr(m_pToolbarControl3);//map
	AddMapToolBarCtr(m_pToolbarControl4);//map

	//�Բ˵����д�ͼ��Ĳ�����������
	//��һ�������ö���
	openAction1 = new QAction( QIcon(":/images/doc-open"), tr("&�򿪲ο�ͼ��"), this );
	openAction1->setStatusTip(tr("Open the First Image"));//�������������ʱ�����ڴ������·�״̬����ʾ״̬
	openAction2 = new QAction( QIcon(":/images/doc-open"), tr("&�򿪴���׼ͼ��"), this );
	openAction2->setStatusTip(tr("Open the Second Image"));//ͬ��
	SurfAction = new QAction( QIcon("tree"), tr("&SURF"), this );
	SurfAction->setStatusTip(tr("SURF Registration"));//ͬ��

	DeleMapLayersAction = new QAction( QIcon(":/image/doc-close"),tr("&�����������"),this);
	DeleMapLayersAction->setStatusTip(tr("Clear all Datas"));

	openBigMapResult = new QAction( QIcon(":/image/doc-open"),tr("&d�򿪴�ͼ��׼���"),this);
	openBigMapResult->setStatusTip(tr("Open the Result of BigMapRegistration."));

	//�ڶ������������뺯����������γ��ź�-�ۻ���
	connect(openAction1, SIGNAL(triggered()), this, SLOT(OpenFile1()));
	connect(openAction2, SIGNAL(triggered()), this, SLOT(OpenFile2()));
	connect(SurfAction, SIGNAL(triggered()), this, SLOT(BigMapRegistration()));
	connect(DeleMapLayersAction,SIGNAL(triggered()), this, SLOT(OnClearMapLayer()));
	connect(openBigMapResult,SIGNAL(triggered()),this,SLOT(Openbigresult()));

	//���������ڲ˵�����Ӧ�ط�����Ӷ���
	ui.menu_1->addAction(openAction1);
	ui.menu_1->addAction(openAction2);
	ui.menu_3->addAction(SurfAction);
	ui.menu->addAction(DeleMapLayersAction);
	ui.menu_3->addAction(openBigMapResult);

	ui.action = openAction1;
	connect(ui.action, SIGNAL(click()), this, SLOT(OpenFile1()));

}

sy_1::~sy_1()
{

}




void sy_1::AddMapToolBarCtr(IToolbarControlPtr pToolbar)
{
	CComVariant varTool;
	long itemIndex;

	if (!pToolbar) 
		return;

	varTool = L"esriControlCommands.ControlsAddDataCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomInTool";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomOutTool";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomInFixedCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomOutFixedCommandl";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapPanTool";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapFullExtentCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomToLastExtentBackCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomToLastExtentForwardCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);

}


void sy_1::OpenFile1()
{
	PyramidBase pyramid1; 
	simage_repath.clear();
	QString file_full1,file_name1,m_strFileName1;
	QString file_path1 = NULL;

	QFileInfo fi;		  
	file_full1 = QFileDialog::getOpenFileName(this,"open the second picture",file_path1);  
	fi = QFileInfo(file_full1);  
	m_strFileName1=fi.absoluteFilePath();

	reImage_full = m_strFileName1.toStdString();////QString ת��Ϊstring///ͼ������·��
	int po = reImage_full.find_last_of('/');
	reFile_path = reImage_full.substr( 0,po+1); ///�ļ���·��

	simage_repath.push_back(reImage_full); ///[0]�б���ԭʼͼ��·��
	simage_repath.push_back(reFile_path);
	/*img.push_back(cvLoadImage(reImage_full.c_str()));*/
	pyramid1.InFilePath = reImage_full.c_str(); 

	pyramid1.Path = reFile_path.c_str();
	pyramid1.CheckPyramid();



	//���������仰���Է�����׼�����У��ݶ��ڴˡ����޸�
		//String  str3("121212.jpg");
		//String str4 = reFile_path + str3; //���ͼ��Ϊ1111.jpg;str4��ʾ���ͼ�������·��
		//resultImage_path = str4;

	//QString path1 = QString::fromStdString(str2);  ////stringת��ΪQstring




	/*QString str5 = QString::fromStdString(str4);*/
	//resultfile = cst_to_conchar(str4);

	//���潫QStringת��Ϊconst char*����
	//QByteArray aByteArray1 = m_strFileName1.toAscii();
	//InfilePath1 = aByteArray1.constData();//��ȡ�ļ�������·��

	/*InfilePath1 = str1.c_str();  *////��string����ֱ��ת��Ϊ��const char*
	

	/*QByteArray aByteArray2 = path1.toAscii();*/
	/*pyramid1.Path =  aByteArray2.constData();*/	//��ȡ�ļ��е�·�������Ա���������ļ�


	//QByteArray aByteArray3 = str5.toAscii();
	////resultfile = aByteArray3.constData();///��ȡ��Ҫ������ļ�·��
	//resultfile = string(aByteArray3.constData());
	


	for (int i = 0;i < pyramid1.iOverViewCount; i++)
	{
		char filepath[1024];
		//sprintf(filepath,"%s%d%s%d%s",reFile_path.c_str(),i,"_",i,".tif");
		//char* layerpath;
		pyramid1.ReadPyramidFile(1,i,filepath);
		string repath1(filepath);
		simage_repath.push_back(repath1);//[2]��ʼ�����������0��ͼ��
		//simage_repath[i] = pyramid1.PyramidLayer_Path[i];
		/*string strpath (pyramid1.PyramidLayer_Path[i]);
		simage_repath[i] = & strpath;*/
		//simage_repath[i] = layerpath;
	}
	
	

	BSTR bstr_str;

	bstr_str = SysAllocString(m_strFileName1.utf16());

	HRESULT hr;

	IRasterLayerPtr pRasterLy(CLSID_RasterLayer);

	hr=pRasterLy->CreateFromFilePath(bstr_str);

	if(FAILED(hr))

		return;

	ILayerPtr pLyr(pRasterLy);

	m_pMapControl1->AddLayer(pLyr,0);

	IActiveViewPtr pActiveView(m_pMapControl1);

	m_pMapControl1->Refresh(esriViewAll);  

//	QMessageBox::information(this, tr("Information"),tr("����"));
}

void sy_1::OpenFile2()
{
	PyramidBase pyramid2; 
	simage_senpath.clear();
	QString file_full2,file_name2,m_strFileName2;
	QString file_path2 = NULL;

	QFileInfo fi;		  
	file_full2 = QFileDialog::getOpenFileName(this,"open the second picture",file_path2);  
	fi = QFileInfo(file_full2);  
	m_strFileName2=fi.absoluteFilePath();
	
	senImage_full = m_strFileName2.toStdString();
	int po = senImage_full.find_last_of('/');
	senFile_path = senImage_full.substr( 0, po + 1 );
	simage_senpath.push_back(senImage_full);///[0]�����ļ�·��
	simage_senpath.push_back(senFile_path);///[1]�����ļ������ļ���·��

	/*img.push_back(cvLoadImage(senImage_full.c_str())); *////����һ�����о��Ѿ����ļ�����洢ͼ�����������
	pyramid2.InFilePath = senImage_full.c_str();

	pyramid2.Path = senFile_path.c_str();
	pyramid2.CheckPyramid();

	for (int i = 0;i < pyramid2.iOverViewCount; i++)
	{
		char filepath[1024];
		sprintf(filepath,"%s%d%s%d%s",senFile_path.c_str(),i,"_",i,".tif");
		//char * layerpath ;
		pyramid2.ReadPyramidFile(1,i,filepath);
		string senpath(filepath);
		simage_senpath.push_back(senpath);//[2]���Ժ󱣴����������ͼ������[2]�����0��(ԭͼ���ص�1/4 * 1/4)��[3]�����1��(ԭͼ���ص�1/8 * 1/8)
		//simage_senpath[i] = pyramid2.PyramidLayer_Path[i];
		
	}

	

	m_strFileName2=fi.absoluteFilePath();

	BSTR bstr_str;

	bstr_str = SysAllocString(m_strFileName2.utf16());

	HRESULT hr;

	IRasterLayerPtr pRasterLy(CLSID_RasterLayer);

	hr=pRasterLy->CreateFromFilePath(bstr_str);

	if(FAILED(hr))

		return;

	ILayerPtr pLyr(pRasterLy);

	m_pMapControl2->AddLayer(pLyr,0);

	IActiveViewPtr pActiveView(m_pMapControl2);

	m_pMapControl2->Refresh(esriViewAll);  

//	QMessageBox::information(this, tr("Information"),tr("����"));
}


void findPairs3( const CvSeq* objectKeypoints, const CvSeq* objectDescriptors,
	const CvSeq* imageKeypoints, const CvSeq* imageDescriptors, vector<int>& ptpairs )
{
	int i;
	CvSeqReader reader, kreader;
	cvStartReadSeq(objectKeypoints, &kreader );
	cvStartReadSeq(objectDescriptors, &reader );
	ptpairs.clear();

	for ( i = 0; i < objectDescriptors->total; i ++ )
	{
		const CvSURFPoint* kp = ( const CvSURFPoint* )kreader.ptr;
		const float* descriptor = ( const float* )reader.ptr;
		CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );
		CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
		int nearest_neighbor = naiveNearestNeighbor3( descriptor, kp->laplacian, imageKeypoints, imageDescriptors );
		if ( nearest_neighbor >= 0 )
		{
			ptpairs.push_back( i );
			ptpairs.push_back( nearest_neighbor );
		}

	}
}

int naiveNearestNeighbor3( const float* vec, int laplacian,
	const CvSeq* model_keypoints,
	const CvSeq* modle_descriptors )
{
	int length = (int)( modle_descriptors->elem_size/sizeof(float) );
	int i, neighbor = -1;
	double d, dist1 = 1e6, dist2 = 1e6;
	CvSeqReader reader, kreader;
	cvStartReadSeq( model_keypoints, &kreader,  0 );
	cvStartReadSeq( modle_descriptors, &reader,  0 );

	for (i = 0; i < model_keypoints->total; i ++ )
	{
		const CvSURFPoint* kp = ( const CvSURFPoint* )kreader.ptr;
		const float* mvec = ( const float* )reader.ptr;
		CV_NEXT_SEQ_ELEM( kreader.seq->elem_size, kreader );
		CV_NEXT_SEQ_ELEM( reader.seq->elem_size, reader );
		if ( laplacian != kp->laplacian )
			continue;
		d = compareSURFDescriptors3( vec, mvec, dist2, length );
		if ( d < dist1 )
		{
			dist2 = dist1;
			dist1 = d;
			neighbor = i;
		}
		else if ( d < dist2 )
			dist2 = d;
	}
	if ( dist1 < 0.55*dist2)
		return neighbor;
	return -1;
}

double compareSURFDescriptors3( const float* d1, const float* d2, double best, int length)
{
	double total_cost = 0;
	assert( length % 4 == 0 );
	for ( int i = 0; i < length; i += 4 )
	{
		double t0 = d1[i] - d2[i];
		double t1 = d1[i + 1] - d2[i + 1];
		double t2 = d1[i + 2] - d2[i + 2];
		double t3 = d1[i + 3] - d2[i + 3];
		total_cost += t0*t0 + t1*t1 +t2*t2 + t3*t3;
		if ( total_cost > best)
			break;
	}
	return total_cost;
}


CvMat* GetH3(vector<int>& ptpairs,CvSeq *CurrentKeypoints,CvSeq *PreKeypoints)
{
	CvMat* H;
	H = ransac_xform3( ptpairs,CurrentKeypoints,PreKeypoints, FEATURE_FWD_MATCH, 4, 0.02, 3.0 );
	return H;
}

CvMat* ransac_xform3( vector<int>& ptpairs,CvSeq *CurrentKeypoints,CvSeq *PreKeypoints, int mtype, 
	int m, double p_badxform, double err_tol)
{
	CvPoint2D64f* pts, * mpts;
	CvMat* M = NULL;
	CvMat* Max_M= NULL;

	double p, in_frac = 0.25;
	int i, nm, in, in_min, in_max = 0, k = 0;//n��number of features in feat

	nm = (int)ptpairs.size()/2;
	if( nm < m )
	{
		fprintf( stderr, "Warning: not enough matches to compute xform, %s" \
			" line %d\n", __FILE__, __LINE__ );
		return NULL;
	}

	in_min = calc_min_inliers3( nm, m, RANSAC_PROB_BAD_SUPP, p_badxform );

	p = pow( 1.0 - pow( in_frac, m ), k );
	i = 0;
	vector<int> Temp_ptpairs;
	vector<int> inliers_ptpairs;
	vector<int> sample_ptpairs;
	while( p > p_badxform )
	{
		draw_ransac_sample3( ptpairs,sample_ptpairs);
		extract_corresp_pts3( sample_ptpairs,CurrentKeypoints,PreKeypoints, m, mtype, &pts, &mpts );
		M = lsq_homog3(pts,mpts, m );

		if( ! M )
			goto iteration_end;
		in = find_consensus3( ptpairs,CurrentKeypoints,PreKeypoints, mtype, M, err_tol,Temp_ptpairs);
		if( in > in_max )
		{
			in_max = in;
			in_frac = (double)in_max / nm;
			inliers_ptpairs=Temp_ptpairs;

			Max_M=cvCloneMat(M);
		}
		cvReleaseMat( &M );

iteration_end:
		release_mem3( pts, mpts);
		p = pow( 1.0 - pow( in_frac, m ), ++k );
	}

	if( in_max >= in_min )
	{
		extract_corresp_pts3( inliers_ptpairs,CurrentKeypoints,PreKeypoints, in_max, mtype, &pts, &mpts );
		M = lsq_homog3( pts, mpts, in_max );

		in = find_consensus3(ptpairs,CurrentKeypoints,PreKeypoints, mtype, M, err_tol, inliers_ptpairs);
		cvReleaseMat( &M );
		release_mem3( pts, mpts );
		extract_corresp_pts3( inliers_ptpairs,CurrentKeypoints,PreKeypoints, in, mtype, &pts, &mpts );
		ptpairs.clear();
		ptpairs=inliers_ptpairs;//���ڵ����д洢��ptpairs��
		
		M = lsq_homog3( pts, mpts, in );
		release_mem3( pts, mpts );
	}
	
	Temp_ptpairs.clear();
	inliers_ptpairs.clear();
	sample_ptpairs.clear();
	return M;
}

static int calc_min_inliers3( int n, int m, double p_badsupp, double p_badxform )
{
	double pi, sum;
	int i, j;

	for( j = m+1; j <= n; j++ )
	{
		sum = 0;
		for( i = j; i <= n; i++ )
		{
			pi = pow( p_badsupp, i - m ) * pow( 1.0 - p_badsupp, n - i + m ) *
				gsl_sf_choose3( n - m, i - m );
			sum += pi;
		}
		if( sum < p_badxform )
			break;
	}
	return j;
}

static	void draw_ransac_sample3( vector<int> ptpairs,vector<int>& sample_ptpairs)
{
	int rank[4];
	for(int i=0;i<4;i++)
		rank[i]=-1;
	int j=0;
	int flag;

	sample_ptpairs.clear();
	while(j<4)
	{
		flag=0;
		int k=rand()%(int)ptpairs.size();
		k=k%2 ? k+1:k;
		for(int i=0;i<4;i++)
		{
			if(k==rank[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0 && k!=((int)ptpairs.size()))
		{
			rank[j]=k;
			j++;
		}
	}
	for(int i=0;i<4;i++)
	{
		int a=rank[i];
		sample_ptpairs.push_back(ptpairs[a]);
		sample_ptpairs.push_back(ptpairs[a+1]);
	}
}

static void extract_corresp_pts3( vector<int> ptpairs,CvSeq *CurrentKeypoints,CvSeq *PreKeypoints,int m, int mtype,
	CvPoint2D64f** pts, CvPoint2D64f** mpts )
{
	CvPoint2D64f* _pts, * _mpts;
	int i,j=0;
	_pts = (struct CvPoint2D64f *)calloc( m, sizeof( CvPoint2D64f ) );
	_mpts = (struct CvPoint2D64f *)calloc( m, sizeof( CvPoint2D64f ) );

	if( mtype == FEATURE_FWD_MATCH )
	{
		for(i=0;i<2*m;i+=2)
		{
			CvSURFPoint* r1 = (CvSURFPoint*)cvGetSeqElem(CurrentKeypoints, ptpairs[i] );
			_pts[j].x=(r1->pt.x);
			_pts[j].y=(r1->pt.y);
			CvSURFPoint* r2 = (CvSURFPoint*)cvGetSeqElem(PreKeypoints, ptpairs[i+1] );
			_mpts[j].x =(r2->pt.x);
			_mpts[j++].y =(r2->pt.y);
		}
	}
	*pts = _pts;
	*mpts = _mpts;
}

static int find_consensus3( vector<int> ptpairs,CvSeq *CurrentKeypoints,CvSeq *PreKeypoints, int mtype,
	CvMat* M, double err_tol,vector<int>& inliers_ptpairs)
{
	CvPoint2D64f pt, mpt;
	double err;
	int i, in = 0;
	double err_square=err_tol*err_tol;
	inliers_ptpairs.clear();
	if( mtype == FEATURE_FWD_MATCH )
		for( i = 0; i < (int)ptpairs.size(); i += 2 )
		{
			CvSURFPoint* r1 = (CvSURFPoint*)cvGetSeqElem( CurrentKeypoints, ptpairs[i] );
			CvSURFPoint* r2 = (CvSURFPoint*)cvGetSeqElem( PreKeypoints, ptpairs[i+1] );
			pt.x=r1->pt.x;
			pt.y=r1->pt.y;
			mpt.x=r2->pt.x;
			mpt.y=r2->pt.y;
			err = homog_xfer_err3( pt, mpt, M );
			if(err<=err_square)
			{
				inliers_ptpairs.push_back(ptpairs[i]);
				inliers_ptpairs.push_back(ptpairs[i+1]);
				in++;
			}
		}
		return in;
}



static	double homog_xfer_err3( CvPoint2D64f pt, CvPoint2D64f mpt, CvMat* H )
{
	CvPoint2D64f xpt = persp_xform_pt4( pt, H );
	double x_diff = xpt.x - mpt.x;
	double y_diff = xpt.y - mpt.y;

	return x_diff * x_diff + y_diff * y_diff;
}

static	CvPoint2D64f persp_xform_pt4( CvPoint2D64f pt, CvMat* T )
{
	CvMat XY, UV;
	double xy[3] = { pt.x, pt.y, 1.0 }, uv[3] = { 0 };
	CvPoint2D64f rslt;

	cvInitMatHeader( &XY, 3, 1, CV_64FC1, xy, CV_AUTOSTEP );
	cvInitMatHeader( &UV, 3, 1, CV_64FC1, uv, CV_AUTOSTEP );
	cvMatMul( T, &XY, &UV );
	rslt = cvPoint2D64f( uv[0] / uv[2], uv[1] / uv[2] );

	return rslt;
}


static CvMat* lsq_homog3( CvPoint2D64f* pts, CvPoint2D64f* mpts, int n )
{
	CvMat* H, * A, * B, X;
	double x[9];
	int i;

	if( n < 4 )
	{
		fprintf( stderr, "Warning: too few points in lsq_homog(), %s line %d\n",
			__FILE__, __LINE__ );
		return NULL;
	}


	A = cvCreateMat( 2*n, 8, CV_64FC1 );
	B = cvCreateMat( 2*n, 1, CV_64FC1 );
	X = cvMat( 8, 1, CV_64FC1, x );
	H = cvCreateMat(3, 3, CV_64FC1);
	cvZero( A );
	for( i = 0; i < n; i++ )
	{
		cvmSet( A, i, 0, pts[i].x );
		cvmSet( A, i+n, 3, pts[i].x );
		cvmSet( A, i, 1, pts[i].y );
		cvmSet( A, i+n, 4, pts[i].y );
		cvmSet( A, i, 2, 1.0 );
		cvmSet( A, i+n, 5, 1.0 );
		cvmSet( A, i, 6, -pts[i].x * mpts[i].x );
		cvmSet( A, i, 7, -pts[i].y * mpts[i].x );
		cvmSet( A, i+n, 6, -pts[i].x * mpts[i].y );
		cvmSet( A, i+n, 7, -pts[i].y * mpts[i].y );
		cvmSet( B, i, 0, mpts[i].x );
		cvmSet( B, i+n, 0, mpts[i].y );
	}
	cvSolve( A, B, &X, CV_SVD );
	x[8] = 1.0;
	X = cvMat( 3, 3, CV_64FC1, x );
	cvConvert( &X, H );

	cvReleaseMat( &A );
	cvReleaseMat( &B );
	return H;
}


double gsl_sf_choose3(unsigned int n, unsigned int m)
{
	unsigned long n1,m1,mfei;
	n1=m1=mfei=1;

	if(n=0)
		n1=1;

	if(m=0)
		return 0;
	else if(m==1)
		return n;
	else
	{
		int mfei=n-m;
		if(m<mfei)
		{
			for(int p=n;p>mfei;p--)
				n1*=p;
			for(int p=m;p>0;p--)
				m1*=p;
		}
		else
		{
			for(int p=n;p>m;p--)
				n1*=p;
			for(int p=mfei;p>0;p--)
				m1*=p;
		}
	}

	double k=n1/m1;
	return k;
}

static __inline void release_mem3( CvPoint2D64f* pts1, CvPoint2D64f* pts2)
{
	free( pts1 );
	free( pts2 );
}

IplImage* convert_to_gray8( IplImage* img )
{
	IplImage* gray8;

	gray8 = cvCreateImage( cvGetSize(img), IPL_DEPTH_8U, 1 );
	cvCvtColor( img, gray8, CV_RGB2GRAY );

	return gray8;
}



const char * cst_to_conchar( CString str )
{
	const size_t strsize = ( str.GetLength() + 1)*2;
	char * pstr = new char[strsize];
	size_t sz = 0;
	wcstombs_s( &sz, pstr, strsize, str, _TRUNCATE );
	int n = atoi(( const char*)pstr); 
	return pstr;
}



///�ú���ʵ��չʾ��׼���
//
//void sy_1::OpenResultFile(string DstImagePath)
//{
//	
//
//	BSTR bstr_str = _bstr_t(DstImagePath.c_str());
//
//
//	//bstr_str = SysAllocString(m_strFileName2.utf16());
//
//	HRESULT hr;
//
//	IRasterLayerPtr pRasterLy(CLSID_RasterLayer);
//
//	hr=pRasterLy->CreateFromFilePath(bstr_str);
//
//	if(FAILED(hr))
//
//		return;
//
//	ILayerPtr pLyr(pRasterLy);
//
//	m_pMapControl3->AddLayer(pLyr,0);
//
//	IActiveViewPtr pActiveView(m_pMapControl3);
//
//	m_pMapControl3->Refresh(esriViewAll);  
//
//	//	QMessageBox::information(this, tr("Information"),tr("����"));
//}



///�ú����������Map�ؼ���ǰ��ʾ��ͼ��
void sy_1::OnClearMapLayer()
{
	HRESULT DeleteLayer1,DeleteLayer2,DeleteLayer3,DeleteLayer4;
	DeleteLayer1 = m_pMapControl1->DeleteLayer(0);////����������������������ݡ�
	DeleteLayer2 = m_pMapControl2->ClearLayers();
//	DeleteLayer3 = m_pMapControl3->ClearLayers();
	DeleteLayer4 = m_pMapControl4->DeleteLayer(0);////����������������������ݡ�
	if (img.size())
	{
		for ( int i = 0; i < img.size(); i ++ )
		{
			cvReleaseImage(&img[i]);
		}
        img.clear();
	}
	ui.bigmapmse->clear();
	ui.bigmaptime->clear();
	ui.bigmaptime2->clear();
	simage_repath.clear();
	simage_senpath.clear();///�ֱ𱣴����ڳ���ƥ���Сͼ��·��
	ResultImagePath.clear();
	rePoint.clear();
	senPoint.clear();
}


double GetRMSE3(vector<int> ptpairs,CvSeq* CurrentKeypoints,CvSeq* PreKeypoints,CvMat* H)
{
	double rmse=0.0;
	int m=ptpairs.size()/2;
	CvSURFPoint r1;
	CvSURFPoint r2;

	for(int i=0;i<m;i++)
	{
		r1.pt=((CvSURFPoint*)cvGetSeqElem( CurrentKeypoints, ptpairs[i*2] ))->pt;
		r2.pt=((CvSURFPoint*)cvGetSeqElem( PreKeypoints, ptpairs[i*2+1] ))->pt;
		r1.pt=persp_xform_pt3(r1.pt,H);
		rmse+=sqrt((r1.pt.x-r2.pt.x)*(r1.pt.x-r2.pt.x)+(r1.pt.y-r2.pt.y)*(r1.pt.y-r2.pt.y));

	}
	rmse=rmse/m;
	ptpairs.clear();
	return rmse;
}


CvPoint2D32f persp_xform_pt3( CvPoint2D32f pt, CvMat* T )
{
	CvMat XY, UV;
	double xy[3] = { pt.x, pt.y, 1.0 }, uv[3] = { 0 };
	CvPoint2D32f rslt;

	cvInitMatHeader( &XY, 3, 1, CV_64FC1, xy, CV_AUTOSTEP );
	cvInitMatHeader( &UV, 3, 1, CV_64FC1, uv, CV_AUTOSTEP );
	cvMatMul( T, &XY, &UV );
	rslt = cvPoint2D32f( uv[0] / uv[2], uv[1] / uv[2] );

	return rslt;
}





///��ƺ�����ȡͼ����ص����򣬲�������з�����ͳ�ƣ�����ȡͳ�ƺ���õ�������������������

void Cut_Count_Overlap(int ilayer)		//����Ĳ���ilayer��ʾ�Ƕ�simage_repath[ilayer]·���е�ͼ����д���
{

	//ͨ�����ݵĲ���ilayer���������ͼ��Դͼ�ķŴ���
	 
	int iscale = static_cast<int>(pow(2.0,ilayer)); 
	

	rePoint.clear(); //����ο�ͼ���вü�������Сͼ�����Ͻ�����
	senPoint.clear();//�������׼ͼ���вü�������Сͼ�����Ͻ�����

	//�������г���ͼ���·��
	string Overlap1 = simage_repath[1] + "reImage_Overlap.jpg";
	string Overlap2 = simage_senpath[1] + "senImage_Overlap.jpg";
	simage_repath.push_back(Overlap1);//
	simage_senpath.push_back(Overlap2);//

	vector<int> ptpairs = ptpairs_befores;
	int num  = ptpairs.size()/2;

	int image1_xsize,image1_ysize; ///����ο�ͼ���С��Ϣ
	int image2_xsize,image2_ysize;//�������׼ͼ���С��Ϣ

	int areaCount1[10] = {0,0,0,0,0,0,0,0,0,0};///ÿһ�����ִ���һ������
	int areaCount2[10] = {0,0,0,0,0,0,0,0,0,0};///
	CvMat* H;///������ʱ����H����
	H = H_2[0]; //����һ����׼����е�H���󴫵ݹ�����//�˴�Ҳ���Ժ������Ϊһ���������ݵĲ���
	double px, py; //����׼ͼ������ڲο�ͼ��ƽ�Ƶľ��룬Ҳ����Ϊ�ص��������Ͻǻ������½ǵ�����
	double h1, h2, h3, h4;
	double dx,dy;///�����ص�����Ĵ�С
	double hx,hy;///����ֿ�ͳ��ʱ��x��y����ÿһС��Ĵ�С��
	px = cvmGet( H, 0, 2 );
	py = cvmGet( H, 1, 2 );
	h1 = abs(px) + 0.5;////Ϊ�������������Լ���0.5����һ�㻹û��������
	h2 = abs(py) + 0.5;///���ص��������Ͻǻ������½ǵ����꼴Ϊ��(h1,h2)
	
	///������Ҫ��ȡͼ��Ĵ�С����
	//�Ȼ�ȡ�ο�ͼ����ߵ���Ϣ
	image1_xsize = img[0]->width;
	image1_ysize = img[0]->height;

	//�ٻ�ȡ����׼ͼ�����Ϣ
	image2_xsize = img[1]->width;
	image2_ysize = img[1]->height;
	
	
	//�����ص�����Ĵ�С
	dx = image1_xsize - h1;
	dy = image1_ysize - h2;

	//�������hx,hy
	double fenkuai3 = 3;
	hx = dx/fenkuai3;
	hy = dy/fenkuai3;

	//IplImage* image0 = cvLoadImage(simage_repath[2].c_str());
	//Mat image0 = cvLoadImage(simage_repath[4].c_str());
	//Mat image1 = cvLoadImage(simage_senpath[4].c_str());

	////�����ص�����ľ��ο�
	//cvRectangle(img[0],cvPoint(h1,h2),cvPoint(image1_xsize,image1_ysize),cvScalar(0,0,255),3,4,0 );
	//cvNamedWindow("OverLapArea",CV_WINDOW_AUTOSIZE);
	//cvShowImage("img[0]WithOverLapArea",img[0]);
	//cvWaitKey(0);
	//cvReleaseImage(&img[0]);

	CvSeq *CurrentKeypoints = objectKeypoints;
	//CvSeq *PreKeypoints = imageKeypoints;
	//CvSURFPoint* r1 = (CvSURFPoint*)cvGetSeqElem(CurrentKeypoints, ptpairs[i] );
	//����Բο�ͼ�����Ѿ�ƥ������������ͳ��
	//char atom_window0[] = "OverLapArea0";  
	//char atom_window1[] = "OverLapArea1";  
	//char atom_window2[] = "OverLapArea2";  
	//char atom_window3[] = "OverLapArea3";  
	//char atom_window4[] = "OverLapArea4";  
	//char atom_window5[] = "OverLapArea5";  
	//char atom_window6[] = "OverLapArea6";  
	//char atom_window7[] = "OverLapArea7";  
	//char atom_window8[] = "OverLapArea8";  

	//char atom1_window0[] = "OverLap1Area0";  
	//char atom1_window1[] = "OverLap1Area1";  
	//char atom1_window2[] = "OverLap1Area2";  
	//char atom1_window3[] = "OverLap1Area3";  
	//char atom1_window4[] = "OverLap1Area4";  
	//char atom1_window5[] = "OverLap1Area5";  
	//char atom1_window6[] = "OverLap1Area6";  
	//char atom1_window7[] = "OverLap1Area7";  
	//char atom1_window8[] = "OverLap1Area8";  

	//ͳ������������Ķ��� 

	for (int i = 0; i < ptpairs.size(); i++)
	{
		CvSURFPoint* r1 = (CvSURFPoint*)cvGetSeqElem(CurrentKeypoints, ptpairs[i] );


		if (r1->pt.x >= h1 && r1->pt.x <= (h1+hx) )
		{
			if (r1->pt.y >= h2 && r1->pt.y <= (h2+hy))
			{
				areaCount1[0]++;

//				rectangle(img[0],cvPoint(h1,h2),cvPoint(h1+hx,h2+hy),cvScalar(255,0,255),2,4,0 );
//				circle(img[0],r1->pt,3,cvScalar(0,255,255),-1,8);

				////cvNamedWindow("OverLapArea0",CV_WINDOW_AUTOSIZE);
				//imshow(atom_window0,img[0]);

			} 
			else if(r1->pt.y > (h2+hy) && r1->pt.y <= (image1_ysize-hy) )
			{
				areaCount1[3]++;

//				rectangle(img[0],cvPoint(h1,h2+hy),cvPoint(h1+hx,image1_ysize-hy),cvScalar(255,0,255),2,4,0 );
//				circle(img[0],r1->pt,3,cvScalar(0,255,255),-1,8);

				////cvNamedWindow("OverLapArea3",CV_WINDOW_AUTOSIZE);
				//imshow(atom_window3,img[0]);

			}
			else if (r1->pt.y > image1_ysize-hy && r1->pt.y <= image1_ysize  )
			{
				areaCount1[6]++;
//				rectangle(img[0],cvPoint(h1,image1_ysize-hy),cvPoint(h1+hx,image1_ysize),cvScalar(255,0,255),2,4,0 );
//				circle(img[0],r1->pt,3,cvScalar(0,255,255),-1,8);

				////cvNamedWindow("OverLapArea6",CV_WINDOW_AUTOSIZE);
				//imshow(atom_window6,img[0]);
			}

		}
		else if ( r1->pt.x > h1+hx && r1->pt.x <= image1_xsize-hx )
		{
			if (r1->pt.y >= h2 && r1->pt.y <= (h2+hy))
			{
				areaCount1[1]++;
//				rectangle(img[0],cvPoint(h1+hx,h2),cvPoint(image1_xsize-hx,image1_ysize),cvScalar(255,0,255),2,4,0 );
//				circle(img[0],r1->pt,3,cvScalar(0,255,255),-1,8);
				////cvNamedWindow("OverLapArea1",CV_WINDOW_AUTOSIZE);
				//imshow(atom_window1,img[0]);
			} 
			else if(r1->pt.y > (h2+hy) && r1->pt.y <= (image1_ysize-hy) )
			{
				areaCount1[4]++;
				//rectangle(img[0],cvPoint(h1+hx,h2+hy),cvPoint(image1_xsize-hx,image1_ysize-hy),cvScalar(255,0,255),2,4,0 );
				//circle(img[0],r1->pt,3,cvScalar(0,255,255),-1,8);
				////cvNamedWindow("OverLapArea4",CV_WINDOW_AUTOSIZE);
				//imshow(atom_window4,img[0]);
			}
			else if (r1->pt.y > image1_ysize-hy && r1->pt.y <= image1_ysize  )
			{
				areaCount1[7]++;
//				rectangle(img[0],cvPoint(h1+hx,image1_ysize-hy),cvPoint(image1_xsize-hx,image1_ysize),cvScalar(255,0,255),2,4,0 );
//				circle(img[0],r1->pt,3,cvScalar(0,255,255),-1,8);
				////cvNamedWindow("OverLapArea7",CV_WINDOW_AUTOSIZE);
				//imshow(atom_window7,img[0]);
			}

		}
		else if ( r1->pt.x > image1_xsize-hx && r1->pt.x <= image1_xsize )
		{
			if (r1->pt.y >= h2 && r1->pt.y <= (h2+hy))
			{
				areaCount1[2]++;
//				rectangle(img[0],cvPoint(image1_xsize-hx,h2),cvPoint(image1_xsize,image1_ysize),cvScalar(255,0,255),2,4,0 );
//				circle(img[0],r1->pt,3,cvScalar(0,255,255),-1,8);
				////cvNamedWindow("OverLapArea2",CV_WINDOW_AUTOSIZE);
				//imshow(atom_window2,img[0]);
			} 
			else if(r1->pt.y > (h2+hy) && r1->pt.y <= (image1_ysize-hy) )
			{
				areaCount1[5]++;
//				rectangle(img[0],cvPoint(image1_xsize-hx,h2+hy),cvPoint(image1_xsize,image1_ysize-hy),cvScalar(255,0,255),2,4,0 );
//				circle(img[0],r1->pt,3,cvScalar(0,255,255),-1,8);
				////cvNamedWindow("OverLapArea5",CV_WINDOW_AUTOSIZE);
				//imshow(atom_window5,img[0]);
			}
			else if (r1->pt.y > image1_ysize-hy && r1->pt.y <= image1_ysize  )
			{
				areaCount1[8]++;
//				rectangle(img[0],cvPoint(image1_xsize-hx,image1_ysize-hy),cvPoint(image1_xsize,image1_ysize),cvScalar(255,0,255),2,4,0 );
//				circle(img[0],r1->pt,3,cvScalar(0,255,255),-1,8);
				////cvNamedWindow("OverLapArea8",CV_WINDOW_AUTOSIZE);
				//imshow(atom_window8,img[0]);
			}
		}
		i++;//��Ϊptpairs�д洢����һ��һ�Ե�������������ţ�����ֵ��Ҫ��ȡ�����вο�ͼ�������������ţ���Ӧ�ø�һ��һȡ
	}


	int maxvaule1 = areaCount1[0]; //��ʾ�����е����ֵ
	int maxnum1 = 0;	//������������ֵ����ţ�Ҳ����Ӧ����
	//ѭ��������ͳ��������������,��������
	for (int i = 1; i < 9; i++)
	{
		
		if (areaCount1[i] > maxvaule1 )
		{
			maxvaule1 = areaCount1[i];
			maxnum1 = i;
		}

	}
// 	char ch;
// 	itoa(maxnum,ch,10);
	//�õ������������������ţ��Ͷ�Ӧ�ػ�����
	//rectangle(img[0],cvPoint(h1,h2),cvPoint(h1+hx,h2+hy),cvScalar(0,0,255),3,4,0 );
	
	switch (maxnum1)
	{
	case 0:
		//�ο�ͼ��Ĳü�
		CvPoint2D64f point0;
		point0.x= iscale*h1;///���У�Ӧ�ð���Щ������Ϊ������
		point0.y = iscale*h2;
		rePoint.push_back(point0);
	//	rectangle(img[0],cvPoint(h1,h2),cvPoint(h1+hx,h2+hy),cvScalar(0,255,255),2,4,0 );
	//	imshow(atom_window0,img[0]);
		ImageCut(simage_repath[0].c_str(),Overlap1.c_str(),point0.x,point0.y,iscale*hx,iscale*hy,"GTiff");
		//����׼ͼ��Ĳü�
		CvPoint2D64f point00;
		point0.x = 0;///���У�Ӧ�ð���Щ������Ϊ������
		point0.y = 0;
		senPoint.push_back(point00);

	//	rectangle(img[1],cvPoint(0,0),cvPoint(hx,hy),cvScalar(255,255,0),2,4,0 );
	//	imshow(atom1_window0,img[1]);
		ImageCut(simage_senpath[0].c_str(),Overlap2.c_str(),0,0,iscale*hx,iscale*hy,"GTiff");

		//waitKey(0);
		break;
	case 1:
		CvPoint2D64f point1;
		point1.x = iscale*(h1+hx);///���У�Ӧ�ð���Щ������Ϊ������
		point1.y = iscale*h2;
		rePoint.push_back(point1);

	//	rectangle(img[0],cvPoint(h1+hx,h2),cvPoint(image1_xsize-hx,h2+hy),cvScalar(0,255,255),2,4,0 );
	//	imshow(atom_window1,img[0]);
		ImageCut(simage_repath[0].c_str(),Overlap1.c_str(),point1.x,point1.y,iscale*(image1_xsize-2*hx),iscale*hy,"GTiff");
		CvPoint2D64f point11;
		point11.x = iscale*hx;///���У�Ӧ�ð���Щ������Ϊ������
		point11.y = 0;
		senPoint.push_back(point11);
	//	rectangle(img[1],cvPoint(hx,0),cvPoint(dx-hx,hy),cvScalar(255,255,0),2,4,0 );
	//	imshow(atom1_window1,img[1]);
		ImageCut(simage_senpath[0].c_str(),Overlap2.c_str(),point11.x,point11.y,iscale*(dx-hx*2),iscale*hy,"GTiff");
		//waitKey(0);
		break;
	case 2:
		CvPoint2D64f point2;
		point2.x =iscale*(image1_xsize-hx);///���У�Ӧ�ð���Щ������Ϊ������
		point2.y = iscale*h2;
		rePoint.push_back(point2);
	//	rectangle(img[0],cvPoint(image1_xsize-hx,h2),cvPoint(image1_xsize,h2+hy),cvScalar(0,255,255),2,4,0 );
	//	imshow(atom_window2,img[0]);
		ImageCut(simage_repath[0].c_str(),Overlap1.c_str(),point2.x,point2.y,iscale*hx,iscale*hy,"GTiff");
		CvPoint2D64f point22;
		point22.x = iscale*(dx-hx);///���У�Ӧ�ð���Щ������Ϊ������
		point22.y = 0;
		senPoint.push_back(point22);

	//	rectangle(img[1],cvPoint(dx-hx,0),cvPoint(dx,hy),cvScalar(255,255,0),2,4,0 );
	//	imshow(atom1_window2,img[1]);
		ImageCut(simage_senpath[0].c_str(),Overlap2.c_str(),point22.x,point22.y,iscale*hx,iscale*hy,"GTiff");
		//waitKey(0);
		break;
	case 3:
		CvPoint2D64f point3;
		point3.x = iscale*h1;///���У�Ӧ�ð���Щ������Ϊ������
		point3.y = iscale*(h2+hy);
		rePoint.push_back(point3);

	//	rectangle(img[0],cvPoint(h1,h2+hy),cvPoint(h1+hx,image1_ysize-hy),cvScalar(0,255,255),2,4,0 );
	//	imshow(atom_window3,img[0]);
		ImageCut(simage_repath[0].c_str(),Overlap1.c_str(),point3.x,point3.y,iscale*hx,iscale*hy,"GTiff");
		CvPoint2D64f point33;
		point33.x = 0;///���У�Ӧ�ð���Щ������Ϊ������
		point33.y = iscale*hy;
		senPoint.push_back(point33);
	//	rectangle(img[1],cvPoint(0,hy),cvPoint(hx,dy-hy),cvScalar(255,255,0),2,4,0 );
	//	imshow(atom1_window3,img[1]);
		ImageCut(simage_senpath[0].c_str(),Overlap2.c_str(),point33.x,point33.y,iscale*hx,iscale*(dy-2*hy),"GTiff");
		//waitKey(0);
		break;
	case 4:	
		CvPoint2D64f point4;
		point4.x = iscale*(h1+hx);///���У�Ӧ�ð���Щ������Ϊ������
		point4.y = iscale*(h2+hy);
		rePoint.push_back(point4);
	//	rectangle(img[0],cvPoint(h1+hx,h2+hy),cvPoint(image1_xsize-hx,image1_ysize-hy),cvScalar(0,255,255),2,4,0 );
	//	imshow(atom_window4,img[0]);
		ImageCut(simage_repath[0].c_str(),Overlap1.c_str(),point4.x,point4.y,iscale*(image1_xsize-2*hx),iscale*(image1_ysize-2*hy),"GTiff");

		CvPoint2D64f point44;
		point44.x = iscale*hx;///���У�Ӧ�ð���Щ������Ϊ������
		point44.y = iscale*hy;
		senPoint.push_back(point44);

//		rectangle(img[1],cvPoint(hx,hy),cvPoint(dx-hx,dy-hy),cvScalar(255,255,0),2,4,0 );
//		imshow(atom1_window4,img[1]);
		ImageCut(simage_senpath[0].c_str(),Overlap2.c_str(),point44.x,point44.y,iscale*(dx-2*hx),iscale*(dy-2*hy),"GTiff");
		//waitKey(0);
		break;
	case 5:
		CvPoint2D64f point5;
		point5.x = iscale*(image1_xsize-hx);///���У�Ӧ�ð���Щ������Ϊ������
		point5.y = iscale*(h2+hy);
		rePoint.push_back(point5);

//		rectangle(img[0],cvPoint(image1_xsize-hx,h2+hy),cvPoint(image1_xsize,image1_ysize-hy),cvScalar(0,255,255),2,4,0 );
//		imshow(atom_window5,img[0]);
		ImageCut(simage_repath[0].c_str(),Overlap1.c_str(),point5.x,point5.y,iscale*hx,iscale*(image1_ysize-2*hy),"GTiff");

		CvPoint2D64f point55;
		point55.x = iscale*(dx-hx);///���У�Ӧ�ð���Щ������Ϊ������
		point55.y = iscale*hy;
		senPoint.push_back(point55);
//		rectangle(img[1],cvPoint(dx-hx,hy),cvPoint(dx,dy-hy),cvScalar(255,255,0),2,4,0 );
//		imshow(atom1_window5,img[1]);
		ImageCut(simage_senpath[0].c_str(),Overlap2.c_str(),point55.x,point55.y,iscale*hx,iscale*(dy-2*hy),"GTiff");


		//waitKey(0);
		break;
	case 6:
		CvPoint2D64f point6;
		point6.x = iscale*h1;///���У�Ӧ�ð���Щ������Ϊ������
		point6.y = iscale*(image1_ysize-hy);
		rePoint.push_back(point6);

//		rectangle(img[0],cvPoint(h1,image1_ysize-hy),cvPoint(h1+hx,image1_ysize),cvScalar(0,255,255),2,4,0 );
//		imshow(atom_window6,img[0]);
		ImageCut(simage_repath[0].c_str(),Overlap1.c_str(),point6.x,point6.y,iscale*hx,iscale*hy,"GTiff");

		CvPoint2D64f point66;
		point66.x = 0;///���У�Ӧ�ð���Щ������Ϊ������
		point66.y = iscale*(dy-hy);
		senPoint.push_back(point66);
//		rectangle(img[1],cvPoint(0,dy-hy),cvPoint(hx,dy),cvScalar(255,255,0),2,4,0 );
//		imshow(atom1_window6,img[1]);
		ImageCut(simage_senpath[0].c_str(),Overlap2.c_str(),point66.x,point66.y,iscale*hx,iscale*hy,"GTiff");

	//	waitKey(0);
		break;
	case 7:
		CvPoint2D64f point7;
		point7.x = iscale*(h1+hx);///���У�Ӧ�ð���Щ������Ϊ������
		point7.y = iscale*(image1_ysize-hy);
		rePoint.push_back(point7);

//		rectangle(img[0],cvPoint(h1+hx,image1_ysize-hy),cvPoint(image1_xsize-hx,image1_ysize),cvScalar(0,255,255),2,4,0 );
//		imshow(atom_window7,img[0]);
		ImageCut(simage_repath[0].c_str(),Overlap1.c_str(),point7.x,point7.y,iscale*(image1_xsize-2*hx),iscale*hy,"GTiff");

		CvPoint2D64f point77;
		point77.x = iscale*hx;///���У�Ӧ�ð���Щ������Ϊ������
		point77.y = iscale*(dy-hy);
		senPoint.push_back(point77);
//		rectangle(img[1],cvPoint(hx,dy-hy),cvPoint(dx-hx,dy),cvScalar(255,255,0),2,4,0 );
//		imshow(atom1_window7,img[1]);
		ImageCut(simage_senpath[0].c_str(),Overlap2.c_str(),point77.x,point77.y,iscale*(dx-2*hx),iscale*hy,"GTiff");


		//waitKey(0);
		break;
	case 8:
		CvPoint2D64f point8;
		point8.x = iscale*(image1_xsize-hx);///���У�Ӧ�ð���Щ������Ϊ������
		point8.y = iscale*(image1_ysize-hy);
		rePoint.push_back(point8);

	//	rectangle(img[0],cvPoint(image1_xsize-hx,image1_ysize-hy),cvPoint(image1_xsize,image1_ysize),cvScalar(0,255,255),2,4,0 );
	//	imshow(atom_window8,img[0]);
		ImageCut(simage_repath[0].c_str(),Overlap1.c_str(),point8.x,point8.y,iscale*hx,iscale*hy,"GTiff");

		CvPoint2D64f point88;
		point88.x = iscale*(dx-hx);///���У�Ӧ�ð���Щ������Ϊ������
		point88.y = iscale*(dy-hy);
		senPoint.push_back(point88);
	//	rectangle(img[1],cvPoint(dx-hx,dy-hy),cvPoint(dx,dy),cvScalar(255,255,0),2,4,0 );
	//	imshow(atom1_window8,img[1]);
		ImageCut(simage_senpath[0].c_str(),Overlap2.c_str(),point88.x,point88.y,iscale*hx,iscale*hy,"GTiff");


		//waitKey(0);
		break;
	}
	

}



void ImageCut(const char* pszSrcFile, const char* pszDstFile, int iStartX, int iStartY, int iSizeX, int iSizeY,const char* pszFormat)
{
	GDALAllRegister();

	GDALDataset *pSrcDS = (GDALDataset*)GDALOpen(pszSrcFile, GA_ReadOnly);
	GDALDataType eDT = pSrcDS->GetRasterBand(1)->GetRasterDataType();

	int iBandCount = pSrcDS->GetRasterCount();

	// ���ݲ��з�Χȷ�����к��ͼ����
	int iDstWidth  = iSizeX;
	int iDstHeight = iSizeY;

	double adfGeoTransform[6] = {0};
	pSrcDS->GetGeoTransform(adfGeoTransform);

	// ��������ļ������ÿռ�ο���������Ϣ
	GDALDriver *poDriver = (GDALDriver *) GDALGetDriverByName(pszFormat);
	GDALDataset *pDstDS = poDriver->Create(pszDstFile, iDstWidth, iDstHeight, iBandCount, eDT, NULL);
	pDstDS->SetGeoTransform(adfGeoTransform);
	pDstDS->SetProjection(pSrcDS->GetProjectionRef());

	int *pBandMap = new int[iBandCount];
	for (int i=0; i<iBandCount; i++)
		pBandMap[i] = i+1;

	if (eDT == GDT_Byte)	// �����8bitͼ��
	{
		// ����������������Ҫ�Ļ��棬���ͼ��̫��Ӧ���÷ֿ鴦��
		char *pDataBuff = new char[iDstWidth*iDstHeight*iBandCount];	

		pSrcDS->RasterIO(GF_Read, iStartX, iStartY, iSizeX, iSizeY, pDataBuff, iSizeX, iSizeY, eDT, iBandCount, pBandMap, 0, 0, 0);
		pDstDS->RasterIO(GF_Write, 0, 0, iSizeX, iSizeY, pDataBuff, iSizeX, iSizeY, eDT, iBandCount, pBandMap, 0, 0, 0);

		delete(pDataBuff);
	}
	else
	{
		// �������͵�ͼ����8bit���ƣ���������Ļ������Ͳ�ͬ����
	}

	delete(pBandMap);

	GDALClose((GDALDatasetH)pSrcDS);
	GDALClose((GDALDatasetH)pDstDS);
	return  ;

}

 ///��ͼ��׼
void sy_1::BigMapRegistration()
{
	
	t2=(double)cvGetTickCount();//��ʼ��ʱ
	t3=(double)cvGetTickCount();//��ʼ��ʱ
	///���ȶ�Сͼ������׼���ʵ��ö�Сͼƥ����㷨
	
	//�ȶ���Խ�����Сͼ��׼�Ľ��ͼ���·�����ݶ������ͼ������ڲο�ͼ���ļ�����

	string dir = simage_repath[1] + "BigMapResultFiles"; ///�ڲο�ͼ���ļ����´����ļ��У�����Сͼ�ʹ�ͼ����׼���
	if(_access(dir.c_str(), 0) != -1)  
	{  
		cout << "�ļ����Ѵ���" <<endl;  
		//system("pause");
	}  
	else  
	{  
		cout << "�ļ��в����ڣ������ļ���" << endl;  
		_mkdir(dir.c_str()); 
		//system("pause");
	} 
	 string dir1 = dir + "\\";

	string sImageResultPath = dir1 + "PyramidImageRegResult.jpg";
	string BigMapResult = dir1 + "BigMapRegistrationResult.tif";
	
	ResultImagePath.clear(); 
	
	ResultImagePath.push_back(dir1);
	ResultImagePath.push_back(sImageResultPath);
	ResultImagePath.push_back(BigMapResult);
	

	 //t2=(double)cvGetTickCount();//��ʼ��ʱ
	//double t1=(double)cvGetTickCount();//��ʼ��ʱ

	//������Ҫ�Ե�һ�ν���ƥ�������ͼ����ѡ�����ں��滹Ҫ�õ��ú������Һ����ƥ�䲻�漰����ͼ��ѡ��ֻ�Ǹ�·���йأ���������ӶԵ�һ��ƥ���ѡ��
	///����ͼƥ�������ѡ����ԣ���һ����Ĭ�ϵ�ѡ�������Լ��趨���ʵĴ�С����ƥ�䣩���ڶ����Ǹ�����ѡ��������Ҫ�ж�
	///
	int i = 1;
	string reImage,senImage;//���������ֱ�������ʱ�洢����ƥ���ͼ��·���������ݸ�ͼ����׼�ĺ���
	for ( i; i ++ ; i < simage_repath.size())
	{
		IplImage * image = cvLoadImage(simage_repath[i].c_str());
		//���ζ�ԭͼ���������������Ĵ�С�����жϣ�ѡ����ʵĲ����ƥ��
		if (image->width <= 1000 || image->height <= 1000)
		{
			reImage = simage_repath[i];
			senImage = simage_senpath[i];
			break;
		}

	}
	
	SURF_ON_TWO(reImage,senImage,sImageResultPath);//��ȡ��������������С��1000��ͼ�����ƥ��
	//t1=(double)(cvGetTickCount()-t1)/(cvGetTickFrequency()*1000*1000.); ///��ʱ����
	//�ڴ˴�������ʾ���ͼ��ĺ���


	//double t2=(double)cvGetTickCount();//��ʼ��ʱ
//	OpenResultFile(sImageResultPath);
	//t2=(double)(cvGetTickCount()-t2)/(cvGetTickFrequency()*1000*1000.); ///��ʱ����

	//double t3=(double)cvGetTickCount();//��ʼ��ʱ
	
	//���ǰ��Խ���������������ѡ�񣬻��߸ı䣬�����������Ҫ�ܹ���Ӧ���ָı�
	//����Ӧ�ö�i�����жϣ���i=1ʱ��������вü���ֱ�ӽ���ƥ�䣬
	CvMat* H;
	if (i == 1)
	{
		H = H_2[0];

		//������е��Ƕ�Сͼ��ƥ��



	}
	else
	{
		//��i������1����˵��Ҫ�Խ�������ĳһ��ͼ�������׼�������Ҫ���вü���ƥ��Ȳ���

		Cut_Count_Overlap(i);//�Խ��ͼ����ƥ����������ͳ�ƣ���������Ȥ������в��в�����

		//t3=(double)(cvGetTickCount()-t3)/(cvGetTickFrequency()*1000*1000.); ///��ʱ����

	//	double t4=(double)cvGetTickCount();//��ʼ��ʱ
		//���ŶԸ���Ȥ�����ͼ�����surfƥ��
		int pathcount = simage_repath.size();
		string OverlapImage1 = simage_repath[pathcount-1];
		string OverlapImage2 = simage_senpath[pathcount-1];
		string OverlapResult = simage_repath[1] + "OverLapResultImage.jpg";
		SURF_ON_TWO(OverlapImage1,OverlapImage2,OverlapResult); //�ú���������Ϻ���H_2[0]�б�����ǵ�ǰͼ���任���H����
	//	t4=(double)(cvGetTickCount()-t4)/(cvGetTickFrequency()*1000*1000.); ///��ʱ����
		//Cut_Count_Overlap();//�Խ��ͼ����ƥ����������ͳ�ƣ���������Ȥ������в��в�����
		//����ӱ任���H��������ȡ�任���������ԶԴ�ͼ���б任
		H = H_2[0];

		double smallhx,smallhy;///�ò�����ʾ�����ü�������Сͼ��ƽ�Ʋ���
		double bighx,bighy;//�ò�����ʾ����׼ͼ������ڲο�ͼ���ƽ�Ʋ���
		//px = cvmGet( H, 0, 2 );
		//py = cvmGet( H, 1, 2 );
		smallhx = cvmGet( H, 0, 2 ) + rePoint[0].x; //����������Ǵ���׼ͼ���и���Ȥ��������ڲο�ͼ���ƽ�ƾ���
		smallhy = cvmGet( H, 1, 2 ) + rePoint[0].y;
		//���ڻ���Ҫ֪�� �ο�ͼ���е�Сͼ����ڴ�ͼ��λ�û�������
		//���ο�ͼ���вü�����Сͼ���Ͻǵ�����
		CvMat *H1; //�����ͼ֮��ı任����������ƽ�������и���

		//����������ݲü����Ĵ���׼ͼ���е�Сͼ�ڲο�ͼ���е�λ�ã����������׼ͼ���ԭͼ�����Ͻ������ڲο�ͼ������ϵ�е�λ�ã�����˵�Ǵ���׼ͼ�����ϽǶ����ƽ������
		bighx = smallhx - senPoint[0].x;
		bighy = smallhy - senPoint[0].y;

		int h1 = abs(bighx) + 0.5;
		int h2 = abs(bighy) + 0.5;
		//�Դ�ͼ��ı任�����е�ƽ�������и���
		H1 = H;
		cvmSet(H1,0,2,bighx);
		cvmSet(H1,1,2,bighy);
		t2=(double)(cvGetTickCount()-t2)/(cvGetTickFrequency()*1000*1000.); ///��ʱ����
		//�õ��任����֮�������Ҫ����һ���µĸ����ͼ�����Դ洢������ͼ��׼�Ľ��

		//ResultImagePath.push_back(BigMapResult);
		GDALAllRegister();
		//��������ͼ�������ݼ���
		GDALDataset* pSrcDS1 = ( GDALDataset* )GDALOpen(simage_repath[0].c_str(),GA_ReadOnly); 
		GDALDataset* pSrcDS2 = ( GDALDataset* )GDALOpen(simage_senpath[0].c_str(),GA_ReadOnly);

		GDALDataType eDT1 = pSrcDS1->GetRasterBand(1)->GetRasterDataType();
		GDALDataType eDT2 = pSrcDS2->GetRasterBand(1)->GetRasterDataType();


		int iBandCount1 = pSrcDS1->GetRasterCount();
		int iBandCount2 = pSrcDS2->GetRasterCount();

		double adfGeoTransform[6] = {0};
		//double adfGeoTransform2[6] = {0};

		pSrcDS1->GetGeoTransform(adfGeoTransform);
		pSrcDS2->GetGeoTransform(adfGeoTransform);


		if (H1)
		{

			GDALDriver *poDriver = (GDALDriver *) GDALGetDriverByName("GTIFF");

			int xsize1 = pSrcDS1->GetRasterXSize();
			int ysize1 = pSrcDS1->GetRasterYSize();
			int xsize2 = pSrcDS2->GetRasterXSize();
			int ysize2 = pSrcDS2->GetRasterYSize();

			int iDstWidth = h1 + xsize2;
			int iDstHeight = h2 + ysize2;

			//������׼���ͼ��
			GDALDataset *pDstDS = poDriver->Create(BigMapResult.c_str(), iDstWidth, iDstHeight, iBandCount1, eDT1, NULL);
			pDstDS->SetGeoTransform(adfGeoTransform);
			pDstDS->SetProjection(pSrcDS1->GetProjectionRef());

			int *pBandMap = new int[iBandCount1];
			for (int i=0; i<iBandCount1; i++)
				pBandMap[i] = i+1;

			// ����������Ҫ���������������жϣ����벻ͬ���͵Ļ��������д������������8bitͼ�������ʾ
			//��������ǽ�����ͼ�񶼱任����׼���ͼ���У�ֻ�����õ��Ƿֿ��˼��
			if (eDT1 == GDT_Byte)	// �����8bitͼ��
			{
				char *pDataBuff = new char[xsize1/2*ysize1/2*iBandCount1];
				//���ο�ͼ��任�����ͼ����
				pSrcDS1->RasterIO(GF_Read, 0,0,xsize1/2, ysize1/2, pDataBuff, xsize1/2,  ysize1/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);
				pDstDS->RasterIO(GF_Write, 0, 0,  xsize1/2,  ysize1/2, pDataBuff,  xsize1/2,  ysize1/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);

				pSrcDS1->RasterIO(GF_Read, 0,ysize1/2,xsize1/2, ysize1/2, pDataBuff, xsize1/2,  ysize1/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);
				pDstDS->RasterIO(GF_Write, 0, ysize1/2,  xsize1/2,  ysize1/2, pDataBuff,  xsize1/2,  ysize1/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);

				pSrcDS1->RasterIO(GF_Read, xsize1/2,0,xsize1/2, ysize1/2, pDataBuff, xsize1/2,  ysize1/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);
				pDstDS->RasterIO(GF_Write, xsize1/2, 0,  xsize1/2,  ysize1/2, pDataBuff,  xsize1/2,  ysize1/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);

				pSrcDS1->RasterIO(GF_Read, xsize1/2,ysize1/2,xsize1/2, ysize1/2, pDataBuff, xsize1/2,  ysize1/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);
				pDstDS->RasterIO(GF_Write, xsize1/2, ysize1/2,  xsize1/2,  ysize1/2, pDataBuff,  xsize1/2,  ysize1/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);

				delete(pDataBuff);
				char *pDataBuff2 = new char[xsize2/2*ysize2/2*iBandCount2];

				pSrcDS2->RasterIO(GF_Read, 0,0,xsize2/2, ysize2/2, pDataBuff2, xsize2/2,  ysize2/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);
				pDstDS->RasterIO(GF_Write,h1,h2, xsize2/2,  ysize2/2, pDataBuff2,  xsize2/2,  ysize2/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);

				pSrcDS2->RasterIO(GF_Read, 0,ysize2/2,xsize2/2, ysize2/2, pDataBuff2, xsize2/2,  ysize2/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);
				pDstDS->RasterIO(GF_Write,h1,h2+ysize2/2, xsize2/2,  ysize2/2, pDataBuff2,  xsize2/2,  ysize2/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);

				pSrcDS2->RasterIO(GF_Read,xsize2/2,0,xsize2/2, ysize2/2, pDataBuff2, xsize2/2,  ysize2/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);
				pDstDS->RasterIO(GF_Write,h1+xsize2/2,h2, xsize2/2,  ysize2/2, pDataBuff2,  xsize2/2,  ysize2/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);

				pSrcDS2->RasterIO(GF_Read,xsize2/2,ysize2/2,xsize2/2, ysize2/2, pDataBuff2, xsize2/2,  ysize2/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);
				pDstDS->RasterIO(GF_Write,h1+xsize2/2 ,h2+ysize2/2, xsize2/2,  ysize2/2, pDataBuff2,  xsize2/2,  ysize2/2, eDT1, iBandCount1, pBandMap, 0, 0, 0);

				delete(pDataBuff2);

				t3=(double)(cvGetTickCount()-t3)/(cvGetTickFrequency()*1000*1000.); ///��ʱ����

			}
			else
			{
				QMessageBox::information(NULL, "Title", "Failed!! !", QMessageBox::Yes, QMessageBox::Yes);

			}

			delete(pBandMap);

			GDALClose((GDALDatasetH)pSrcDS1);
			GDALClose((GDALDatasetH)pSrcDS2);
			GDALClose((GDALDatasetH)pDstDS);

		}


	}
	
	QString s1 = QString::number(t2,'g',6);
	ui.bigmaptime->setText(s1);
	QString mse = QString::number(mese2,'g',6);
	ui.bigmapmse->setText(mse);
	QString s2 = QString::number(t3,'g',6);
	ui.bigmaptime2->setText(s2);



	OpenResultFile1(ResultImagePath[2]);
}


void SURF_ON_TWO(string SrcReImagePath, string SrcSenImagePath, string DstImagePath )
{
	cv::initModule_nonfree();
	img.clear();
	img.push_back(cvLoadImage(SrcReImagePath.c_str())); //����Դ����Ľ��������е�һ��(�������Ǵӵ�0�㿪ʼ������)���е���׼����֮���Բ����öԵ�һ����г���׼��ԭ���������ֲ����ﵽ��Ŀ�Ķ��ǻ�ȡ�ص��������Ȥ�Ĳ��֣�����ʱ��ȴ��һ�������ң��������ܴ��ͼ���ʱ�򣬼�ʹ�ǵ�0��ͼ��Ҳ�޷���opencv�������ۺ�������ʹ�õ�1�����ȫ����Ч�ġ�
	img.push_back(cvLoadImage(SrcSenImagePath.c_str())); 
	//ptpairs_befores.clear();
	CvMat* H;
	CvMat h;
	CvMat* H1=&h;
	double a[9];

	double sfx,sfy;
	double rotate;
	double R11,R12,R21,R22;
	char PX[20]={""},PY[20]={""};
	char SFX[20]={""},SFY[20]={""};
	char ROTATE[20]={""};
	char TIME[20]={""};
	CString d=",";
	int dian;
	char dot[20]={""};
	char time[20]={""};
	vector<int>ptpairs;

	if ( !img[0] || !img[1] )
	{
		QMessageBox::information( 0, "Tips", "Please open another image!", 0, 0 );
		return;
	}
	CvMemStorage* storage = cvCreateMemStorage(0);//�ڴ�洢��
	static CvScalar colors[] =
	{
		{{ 0, 0, 255 }},
		{{ 0, 128, 255 }},
		{{ 0, 255, 255 }},
		{{ 0, 255, 0 }},
		{{ 255, 128, 0 }},
		{{ 255, 255, 0 }},
		{{ 255, 0, 0 }},
		{{ 255, 0, 255 }},
		{{ 255, 255, 255 }}
	};//���������ڵ�ɫ��Ķ���
	IplImage* img1 = convert_to_gray8( img[0] );
	IplImage* img2 = convert_to_gray8( img[1] );

	CvSURFParams params = cvSURFParams( 1000, 1 );
	cv::initModule_nonfree();
	cvExtractSURF( img1, 0, &objectKeypoints, &objeceDescriptors, storage, params );
	cvExtractSURF( img2, 0, &imageKeypoints, &imageDescriptors, storage, params );
	findPairs3( imageKeypoints, imageDescriptors, objectKeypoints, objeceDescriptors,ptpairs);

	if ( ptpairs.size() / 2  < 4 )
	{
		QMessageBox::information(0, "Tips", "Image Registration By SURF Failed !", 0, 0 );
		mese2=0;
		num2=0;
		return;
	}
	else
	{
		num2 = ptpairs.size() / 2;
		H = GetH3( ptpairs, imageKeypoints, objectKeypoints);////�ڸú������ù����н�����RANSAC�㷨

		if ( H )
		{
			mese2 = GetRMSE3( ptpairs, imageKeypoints, objectKeypoints, H );
			ptpairs_befores = ptpairs;////�Ѿ���RANSAC�㷨֮����ڵ����б���Ϊ������ѡ��������
			H_2.clear();
			H_2.push_back(H);
			double px, py;
			int h1, h2;
			px = cvmGet( H, 0, 2 );
			py = cvmGet( H, 1, 2 );
			h1 = abs(px) + 0.5;
			h2 = abs(py) + 0.5;
			IplImage* xformed;
			xformed = cvCreateImage( cvSize( h1 + img[1]->width, h2 + img[1]->height ), IPL_DEPTH_8U, 3 );
			cvWarpPerspective( img[1], xformed, H, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll(0) );
			//͸��ͶӰ
			cvSetImageROI(xformed, cvRect( 0, 0, img[0]->width, img[0]->height ) );
			cvAddWeighted( img[0], 1, xformed, 0, 0, xformed );
			//Ȩ�غ�������������ֱ��ǣ���һ�����飬Ȩֵ���ڶ������飬Ȩֵ�����ʱ����ӳ�����������
			cvResetImageROI( xformed );

			cvSaveImage( DstImagePath.c_str(), xformed );

			//cvShowImage(xformed)
			cvReleaseImage(&xformed);

		}

	}

}

void sy_1::Openbigresult()
{
	OpenResultFile1(ResultImagePath[2]);
}
void sy_1::OpenResultFile1(string DstImagePath)
{
	PyramidBase pyramid1; 
	pyramid1.InFilePath = DstImagePath.c_str(); 
	pyramid1.Path = ResultImagePath[0].c_str();
	pyramid1.CheckPyramid();

	BSTR bstr_str = _bstr_t(DstImagePath.c_str());


	//bstr_str = SysAllocString(m_strFileName2.utf16());

	HRESULT hr;

	IRasterLayerPtr pRasterLy(CLSID_RasterLayer);

	hr=pRasterLy->CreateFromFilePath(bstr_str);

	if(FAILED(hr))

		return;

	ILayerPtr pLyr(pRasterLy);

	m_pMapControl4->AddLayer(pLyr,0);

	IActiveViewPtr pActiveView(m_pMapControl4);

	m_pMapControl4->Refresh(esriViewAll);  

	//	QMessageBox::information(this, tr("Information"),tr("����"));
}