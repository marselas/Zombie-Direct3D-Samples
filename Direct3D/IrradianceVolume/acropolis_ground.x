xof 0303txt 0032
template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template IndexedColor {
 <1630b820-7842-11cf-8f52-0040333594a3>
 DWORD index;
 ColorRGBA indexColor;
}

template MeshVertexColors {
 <1630b821-7842-11cf-8f52-0040333594a3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template VertexElement {
 <f752461c-1e23-48f6-b9f8-8350850f336f>
 DWORD Type;
 DWORD Method;
 DWORD Usage;
 DWORD UsageIndex;
}

template DeclData {
 <bf22e553-292c-4781-9fea-62bd554bdd93>
 DWORD nElements;
 array VertexElement Elements[nElements];
 DWORD nDWords;
 array DWORD data[nDWords];
}


Frame DXCC_ROOT {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Frame persp {
  

  FrameTransformMatrix {
   -0.745476,0.000000,-0.666532,0.000000,0.448630,0.739569,-0.501765,0.000000,0.492947,-0.673081,-0.551331,0.000000,-174.343094,244.504089,194.992142,1.000000;;
  }

  Frame perspShape {
   

   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }
  }
 }

 Frame top {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.236301,103.635559,7.786925,1.000000;;
  }

  Frame topShape {
   

   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }
  }
 }

 Frame front {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.008950,2.255381,-102.720581,1.000000;;
  }

  Frame frontShape {
   

   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }
  }
 }

 Frame side {
  

  FrameTransformMatrix {
   0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,100.917671,7.981136,-0.030593,1.000000;;
  }

  Frame sideShape {
   

   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }
  }
 }

 Frame sceneGroup {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Frame environmentGroup {
   

   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }

   Frame ground {
    

    FrameTransformMatrix {
     1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
    }

    Frame groundShape {
     

     FrameTransformMatrix {
      1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
     }

     Mesh groundShape_Mesh {
      15;
      92.535004;0.000000;-0.000000;,
      92.535004;0.000000;92.535271;,
      46.267502;0.000000;92.535271;,
      46.267502;0.000000;-0.000000;,
      -0.000000;0.000000;-0.000000;,
      -0.000000;0.000000;92.535271;,
      -46.267502;0.000000;92.535271;,
      -46.267502;0.000000;-0.000000;,
      -46.267502;-0.000000;-92.535271;,
      -0.000000;-0.000000;-92.535271;,
      -92.535004;-0.000000;-92.535271;,
      -92.535004;0.000000;-0.000000;,
      -92.535004;0.000000;92.535271;,
      46.267502;-0.000000;-92.535271;,
      92.535004;-0.000000;-92.535271;;
      16;
      3;0,3,1;,
      3;1,3,2;,
      3;4,7,5;,
      3;5,7,6;,
      3;8,7,9;,
      3;9,7,4;,
      3;10,11,8;,
      3;8,11,7;,
      3;6,7,12;,
      3;12,7,11;,
      3;13,3,14;,
      3;14,3,0;,
      3;9,4,13;,
      3;13,4,3;,
      3;2,3,5;,
      3;5,3,4;;

      MeshNormals {
       15;
       0.000000;1.000000;-0.000000;,
       0.000000;1.000000;-0.000000;,
       0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;,
       0.000000;1.000000;-0.000000;,
       0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;,
       -0.000000;1.000000;-0.000000;;
       16;
       3;0,3,1;,
       3;1,3,2;,
       3;4,7,5;,
       3;5,7,6;,
       3;8,7,9;,
       3;9,7,4;,
       3;10,11,8;,
       3;8,11,7;,
       3;6,7,12;,
       3;12,7,11;,
       3;13,3,14;,
       3;14,3,0;,
       3;9,4,13;,
       3;13,4,3;,
       3;2,3,5;,
       3;5,3,4;;
      }

      MeshTextureCoords {
       15;
       0.999002;0.500000;,
       0.999002;0.000998;,
       0.749501;0.000998;,
       0.749501;0.500000;,
       0.500000;0.500000;,
       0.500000;0.000998;,
       0.250499;0.000998;,
       0.250499;0.500000;,
       0.250499;0.999002;,
       0.500000;0.999002;,
       0.000998;0.999002;,
       0.000998;0.500000;,
       0.000998;0.000998;,
       0.749501;0.999002;,
       0.999002;0.999002;;
      }

      MeshVertexColors {
       15;
       0;0.000000;0.000000;0.000000;0.000000;;,
       1;0.000000;0.000000;0.000000;0.000000;;,
       2;0.000000;0.000000;0.000000;0.000000;;,
       3;0.000000;0.000000;0.000000;0.000000;;,
       4;0.000000;0.000000;0.000000;0.000000;;,
       5;0.000000;0.000000;0.000000;0.000000;;,
       6;0.000000;0.000000;0.000000;0.000000;;,
       7;0.000000;0.000000;0.000000;0.000000;;,
       8;0.000000;0.000000;0.000000;0.000000;;,
       9;0.000000;0.000000;0.000000;0.000000;;,
       10;0.000000;0.000000;0.000000;0.000000;;,
       11;0.000000;0.000000;0.000000;0.000000;;,
       12;0.000000;0.000000;0.000000;0.000000;;,
       13;0.000000;0.000000;0.000000;0.000000;;,
       14;0.000000;0.000000;0.000000;0.000000;;;
      }

      DeclData {
       2;
       2;0;6;0;,
       2;0;7;0;;
       90;
       0,
       2760716287,
       3212836863,
       1065353216,
       0,
       0,
       2147483648,
       2760716287,
       3212836863,
       1065353215,
       2553241921,
       0,
       0,
       2760716287,
       3212836863,
       1065353216,
       0,
       0,
       0,
       2760716287,
       3212836863,
       1065353216,
       397369666,
       0,
       0,
       2760716287,
       3212836863,
       1065353216,
       397369666,
       0,
       0,
       2760716287,
       3212836863,
       1065353215,
       0,
       0,
       0,
       2760716287,
       3212836863,
       1065353216,
       0,
       0,
       0,
       2760716287,
       3212836863,
       1065353216,
       397369668,
       0,
       0,
       2760716287,
       3212836863,
       1065353216,
       405758276,
       0,
       0,
       2760716287,
       3212836863,
       1065353216,
       405758274,
       0,
       0,
       2760716288,
       3212836863,
       1065353216,
       405758276,
       0,
       0,
       2760716287,
       3212836863,
       1065353216,
       405758276,
       0,
       0,
       2760716287,
       3212836863,
       1065353215,
       405758273,
       0,
       0,
       2760716287,
       3212836863,
       1065353216,
       405758274,
       0,
       0,
       2760716287,
       3212836863,
       1065353215,
       405758273,
       0;
      }
     }
    }
   }
  }
 }

 Frame polySurface3 {
  

  FrameTransformMatrix {
   1.660737,0.000000,0.000000,0.000000,0.000000,1.660737,0.000000,0.000000,0.000000,0.000000,1.660737,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Frame transform1 {
   

   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }

   Frame polySurfaceShape27 {
    

    FrameTransformMatrix {
     1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
    }
   }
  }
 }
}