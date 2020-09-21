#include "GmshConfig.h"
#include "GModel.h"
#include "meshGRegionHxt.h"
#include "meshGFaceHxt.h"
#include "Context.h"
#include "MVertex.h"
#include "GFace.h"
#include "GmshMessage.h"
#include "meshWinslow2d.h"

#include "fastScaledCrossField.h"
#include "gmshCrossFields.h"

#if defined(HAVE_HXT)
extern "C" {
  //#include "hxt_mesh.h"
#include "hxt_gmsh_point_gen_main.h"
#include "hxt_point_gen_options.h"
}

static HXTStatus messageCallback(HXTMessage *msg)
{
  if(msg) Msg::Info("%s", msg->string);
  return HXT_STATUS_OK;
}


//int getDirectionsAndScaling(GModel *gm,
                            //const std::map<std::array<size_t,2>,double> &edgeTheta,
                            //const std::vector<size_t> &nodeTags,
                            //const std::vector<double> &scaling,
                            //std::vector<SVector3> &dir1,
                            //std::vector<SVector3> &dir2,
                            //std::vector<double> &sizemap)
//{
  //[> Combine cross directions and scaling to create view <]
  //for (GFace* gf: faces) {
    //for (MTriangle* t: gf->triangles) {
      //SVector3 N = tri_normal(t);

      //[> Compute one branch at triangle vertices <]

      //SVector3 refCross = {0.,0.,0.};
      //SVector3 avgCross = {0.,0.,0.};
      //SVector3 lifted_dirs[3];
      //for (size_t le = 0; le < 3; ++le) {
        //[> Get cross angle <]
        //std::array<MVertex*,2> edge = {t->getVertex(le),t->getVertex((le+1)%3)};
        //if (edge[0]->getNum() > edge[1]->getNum()) std::reverse(edge.begin(),edge.end());
        //auto it = edgeTheta.find(std::array<size_t,2>{edge[0]->getNum(),edge[1]->getNum()});
        //if (it == edgeTheta.end()) {
          //Msg::Error("Edge (%li,%li) not found in edgeTheta",edge[0]->getNum(),edge[1]->getNum());
          //return -1;
        //}
        //double A = it->second;

        //[> Local reference frame <]
        //SVector3 tgt = edge[1]->point() - edge[0]->point();
        //if (tgt.norm() < 1.e-16) {
          //Msg::Warning("Edge (tri=%i,le=%i), length = %.e", t->getNum(), le, tgt.norm());
          //if (tgt.norm() == 0.) {return -1;}
        //}
        //tgt.normalize();
        //SVector3 tgt2 = crossprod(N,tgt);
        //tgt2.normalize();

        //SVector3 cross1 = tgt * cos(A) + tgt2 * sin(A);
        //cross1.normalize();

        //SVector3 cross2 = crossprod(N,cross1);
        //cross2.normalize();

        //if (le == 0) {
          //refCross = cross1;
          //avgCross = avgCross + cross1;
          //lifted_dirs[le] = refCross;
        //} else {
          //SVector3 candidates[4] = {cross1,-1.*cross1,cross2,-1.*cross2};
          //SVector3 closest = {0.,0.,0.};
          //double dotmax = -DBL_MAX;
          //for (size_t k = 0; k < 4; ++k) {
            //if (dot(candidates[k],refCross) > dotmax) {
              //closest = candidates[k];
              //dotmax = dot(candidates[k],refCross);
            //}
          //}
          //lifted_dirs[le] = closest;
          //avgCross = avgCross + closest;
        //}
      //}
      //SVector3 edge_dirs[3];
      //for (size_t le = 0; le < 3; ++le) {
        //double se = 0.5 * (num_to_scaling[t->getVertex(le)->getNum()] 
            //+ num_to_scaling[t->getVertex((le+1)%3)->getNum()]);
        //edge_dirs[le] = se * lifted_dirs[le];
      //}
      //SVector3 vertex_dirs[3];
      //for (size_t lv = 0; lv < 3; ++lv) {
        //SVector3 lambda = {0.,0.,0.};
        //lambda[lv] = 1.;
        //vertex_dirs[lv] = crouzeix_raviart_interpolation(lambda,edge_dirs);
      //}

      //[> Add triangle coords+vectors to view <]
      //for (size_t d = 0; d < 3; ++d) {
        //for (size_t lv = 0; lv < 3; ++lv) {
          //datalist.push_back(t->getVertex(lv)->point().data()[d]);
        //}
      //}
      //for (size_t lv = 0; lv < 3; ++lv) {
        //for (size_t d = 0; d < 3; ++d) {
          //datalist.push_back(vertex_dirs[lv][d]);
        //}
      //}
    //}
  //}

  //return 0;
/*}*/


int meshGFaceHxt(GModel *gm)
{


  //int targetNumberOfQuads = 2000;

  //int nbDiffusionLevels = 7;
  //double thresholdNormConvergence = 0.01; 
  //int nbBoundaryExtensionLayer = 1;

  ////int dataListViewTag = -1;
//[>  computeScaledCrossFieldView(gm,<]
                              ////dataListViewTag,
                              ////targetNumberOfQuads,
                              ////nbDiffusionLevels,
                              ////thresholdNormConvergence,
                              ////nbBoundaryExtensionLayer,
                              ////"ScaledCrossField");

  //Msg::Debug("compute scaled cross field ...");
//#ifdef HAVE_QUADMESHINGTOOLS
  //std::vector<GFace*> faces;
  //for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    //faces.push_back(*it);
  //}
  //std::map<std::array<size_t,2>,double> edgeTheta;
  //for (GFace* gf: faces) {
    //Msg::Debug("- compute cross field for face %i ...",gf->tag());
    //int status = computeCrossFieldWithHeatEquation({gf}, edgeTheta, nbDiffusionLevels, thresholdNormConvergence,
        //nbBoundaryExtensionLayer);
    //if (status != 0) {
      //Msg::Error("failed to compute cross field for face %i",gf->tag());
    //}
  //}

  //std::vector<size_t> nodeTags;
  //std::vector<double> scaling;
  //int status = computeCrossFieldScaling(faces, edgeTheta, targetNumberOfQuads, nodeTags, scaling);
  //if (status != 0) {
    //Msg::Error("failed to compute cross field scaling");
    //return -1;
  //}

  //std::vector<SVector3> dir1, dir2;
  //std::vector<double> scaling;
//#endif


  HXT_CHECK(hxtSetMessageCallback(messageCallback));



  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(&mesh));

  std::map<int, std::vector<double> > dataH;
  std::map<int, std::vector<double> > dataDir;
  std::map<int, std::vector<double> > dataDirOrtho;
  computeCrossFieldAndH(gm,dataH,dataDir,dataDirOrtho);

  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  HXT_CHECK(Gmsh2Hxt(gm, mesh, v2c, c2v));

  /// put the cross field and conformal factor into a big vector
  double *data = (double*)malloc(c2v.size()*sizeof(double)*7);
  for (size_t i = 0; i< c2v.size()*7 ; i++)data [i] = 0.0;

  std::map<int, std::vector<double> > :: iterator it = dataDir.begin();
  for ( ; it != dataDir.end() ; ++it){
    MElement *e = gm->getMeshElementByTag (it->first);
    std::vector<double> &dir      = it->second;
    std::vector<double> &dirOrtho = dataDirOrtho[it->first];
    SVector3 t1 (dir[0],dir[1],dir[2]);
    SVector3 t2 (dirOrtho[0],dirOrtho[1],dirOrtho[2]);
    SVector3 n = crossprod(t1,t2);

    for (size_t i=0;i< e->getNumVertices();i++){
      MVertex *v = e->getVertex (i);
      if (v2c.find(v)  == v2c.end())Msg::Error ("FILE %s LINE %d Cannot find vertex %lu",__FILE__,__LINE__,v->getNum()); 
      if (v2c[v] >= v2c.size())Msg::Error ("FILE %s LINE %d Bad numbering v2c[%lu] = %lu",__FILE__,__LINE__,v->getNum(),v2c[v]); 
      double *nn = data+7*v2c[v];
      nn[0] += n[0];
      nn[1] += n[1];
      nn[2] += n[2];
      SVector3 t (nn[3],nn[4],nn[5]);
      if (t.norm () < 1.e-12){
        nn[3] = t1.x();
        nn[4] = t1.y();
        nn[5] = t1.z();
      }
      else {
        double x0 = dot (t,t1);
        double x1 = dot (t,-t1);
        double x2 = dot (t,t2);
        double x3 = dot (t,-t2);
        if (x0 > x1 && x0 > x2 && x0 > x3){
          nn[3]+= t1.x();nn[4]+= t1.y();nn[5]+= t1.z();
        }
        else if (x1 > x0 && x1 > x2 && x1 > x3){
          nn[3]-= t1.x();nn[4]-= t1.y();nn[5]-= t1.z();
        }
        else if (x2 > x0 && x2 > x1 && x2 > x3){
          nn[3]+= t2.x();nn[4]+= t2.y();nn[5]+= t2.z();
        }
        else{
          nn[3]-= t2.x();nn[4]-= t2.y();nn[5]-= t2.z();
        }	  
      }
    }    
  }

  for (size_t i = 0; i< c2v.size() ; i++){
    double *n = data+ 7*i;

    SVector3 t (n[0],n[1],n[2]); t.normalize();
    n[0] = t.x();n[1] = t.y();n[2] = t.z();
    t = SVector3(n[3],n[4],n[5]); t.normalize();
    n[3] = t.x();n[4] = t.y();n[5] = t.z();

    if (dataH.find(c2v[i]->getNum()) != dataH.end()){    
      n[6] = dataH[c2v[i]->getNum()][0];
    }
    else {
      Msg::Warning ("Vertex %lu has no value for H",c2v[i]->getNum());
    }
  }

  ///// HERE WE NEED THE CODE TO THE REMESHING STUFF

  HXTMesh *fmesh;
  HXT_CHECK(hxtMeshCreate(&fmesh));

  // TODO 
  HXTPointGenOptions opt = { .verbosity = 0,
    .generateLines = 1,
    .generateSurfaces = 1,
    .generateVolumes = 0,
    .remeshSurfaces = 1,
    .quadSurfaces = 1,
    .walkMethod2D = 0,
    .walkMethod3D = 0,
    .dirType = 0,
    .uniformSize = 2.5,
    .areaThreshold = 10e-9,
    .tolerance = 10e-9,
    .numTris = 0};

  printf("INPUT SIZE = \n");
  float temp = 0;
  scanf("%f",&temp);
  opt.uniformSize = temp;


  HXT_CHECK(hxtGmshPointGenMain(mesh,&opt,data,fmesh));
  v2c.clear();
  c2v.clear();
  //  HXT_CHECK(Hxt2Gmsh(gm, fmesh, v2c, c2v));

  GModel *gm2 = new GModel(gm->getName());

  gm2->readMSH("finalmesh.msh");	  	  


  printf("WINSLOW START\n");
  meshWinslow2d (gm2);
  printf("WINSLOW ENDS\n");
  gm2->writeMSH("finalmesh_smoothed.msh", 4.0, false, true);	  	  
  HXT_CHECK(hxtMeshDelete(&fmesh));


  ///// END OF HERE WE NEED THE CODE TO THE REMESHING STUFF

  free (data);
  HXT_CHECK(hxtMeshDelete(&mesh));

  //  meshWinslow2d (gm);

  return 0;
}


#else

int meshGFaceHxt(GModel *gm)
{
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
  return -1;
}

#endif
