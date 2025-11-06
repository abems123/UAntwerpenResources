<<<<<<< HEAD
//
// Created by yaman haj ahmad on 19/03/2025.
//

#include "Figure.h"
#include <iostream>
#include <cmath>

//dit functie spreekt voor zich, 2 punten (van de lines van line2d files/de lsystemen stuk) zullen met elkaar verbonden worden in een
//2d image.
void Figure::point2dTOline2d() {
    //elk face hier bevat maar 2 punten (eigenlijk index van 2 punten in points2D vector). (om lijn te maken)
    for (auto face: faces) {
        Line2D lijn;
        pair<int,int> check = {face.point_indexes.at(0),face.point_indexes.at(1)};
        pair<int,int> check2 = {face.point_indexes.at(1),face.point_indexes.at(0)};
        if (LinesDone.find(check) != LinesDone.end() or LinesDone.find(check2) != LinesDone.end()) {
            continue;
        }
        else {
            lijn.p1 = points2D.at(face.point_indexes.at(0));
            lijn.p2 = points2D.at(face.point_indexes.at(1));
            lijn.color = color;

            //z1 en z2 zijn de z cordinaten opgeslagen om met zbuffering te werken in het geval van zbuffering.
            lijn.z1 = points.at(face.point_indexes.at(0)).z;
            lijn.z2 = points.at(face.point_indexes.at(1)).z;
            lijnen.push_back(lijn);
        }
    }
}


void Figure::figurePointsToLine2d() {
    //faces hier kan zo veel punten bevatten (eigenlijk daarmee bedoel ik de index van punten in points2D vector)
    for (auto face: faces){
        //voor het itereren moet ik kijken hoeveel indexen in de face vector zitten.
        int i_max = face.point_indexes.size();

        //ik ga genoeg itereren om alles in te lezen
        for (int i = 0; i<i_max-1; i++){
            Line2D lijn;
            pair<int,int> check = {face.point_indexes.at(i),face.point_indexes.at(i+1)};
            pair<int,int> check2 = {face.point_indexes.at(i+1),face.point_indexes.at(i)};
            if (LinesDone.find(check) != LinesDone.end() or LinesDone.find(check2) != LinesDone.end()) {
                continue;
            }
            else {
                lijn.p1 = points2D.at(face.point_indexes.at(i));
                lijn.p2 = points2D.at(face.point_indexes.at(i + 1));
                lijn.color = color;

                //de z cordinaten van de 3d punten opslaan om later met zbuffering te werken wanneer het moet.
                lijn.z1 = points.at(face.point_indexes.at(i)).z;
                lijn.z2 = points.at(face.point_indexes.at(i + 1)).z;

                lijnen.push_back(lijn);
            }
        }
    }
}
/*
    alle figuren zijn basically hardcoded op basis van wat in de cursus stond.
*/
void Figure::createTetrahedron(){
    if (!FigureGenerated){
        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        Vector3D p1 = Vector3D::point(1,-1,-1);
        Vector3D p2 = Vector3D::point(-1,1,-1);
        Vector3D p3 = Vector3D::point(1,1,1);
        Vector3D p4 = Vector3D::point(-1,-1,1);

        points.push_back(p1); points.push_back(p2); points.push_back(p3); points.push_back(p4);

        Face f1; f1.point_indexes = {0,1,2,0};faces.push_back(f1);
        Face f2; f2.point_indexes = {1,3,2,1};faces.push_back(f2);
        Face f3; f3.point_indexes = {0,3,1,0};faces.push_back(f3);
        Face f4; f4.point_indexes = {0,2,3,0};faces.push_back(f4);

        FigureGenerated = true;
    }
    else{
        cout << "already a figure generated"<<endl;
    }
}

void Figure::createCube() {
    if (!FigureGenerated) {
        points.clear();points2D.clear();lijnen.clear();faces.clear();

        Vector3D p1 = Vector3D::point(1, -1, -1);points.push_back(p1);
        Vector3D p2 = Vector3D::point(-1, 1, -1);points.push_back(p2);
        Vector3D p3 = Vector3D::point(1, 1, 1);points.push_back(p3);
        Vector3D p4 = Vector3D::point(-1, -1, 1);points.push_back(p4);
        Vector3D p5 = Vector3D::point(1, 1, -1);points.push_back(p5);
        Vector3D p6 = Vector3D::point(-1, -1, -1);points.push_back(p6);
        Vector3D p7 = Vector3D::point(1, -1, 1);points.push_back(p7);
        Vector3D p8 = Vector3D::point(-1, 1, 1);points.push_back(p8);


        Face f1; f1.point_indexes = {0,4,2,6,0};faces.push_back(f1);
        Face f2; f2.point_indexes = {4,1,7,2,4};faces.push_back(f2);
        Face f3; f3.point_indexes = {1,5,3,7,1};faces.push_back(f3);
        Face f4; f4.point_indexes = {5,0,6,3,5};faces.push_back(f4);
        Face f5; f5.point_indexes = {6,2,7,3,6};faces.push_back(f5);
        Face f6; f6.point_indexes = {0,5,1,4,0};faces.push_back(f6);

        FigureGenerated = true;
    }
    else{
        cout << "already a figure generated"<<endl;
    }
}

void Figure::creatOctahedron() {
    if (!FigureGenerated) {
        points.clear();points2D.clear();lijnen.clear();faces.clear();

        Vector3D p1 = Vector3D::point(1, 0, 0);points.push_back(p1);
        Vector3D p2 = Vector3D::point(0, 1, 0);points.push_back(p2);
        Vector3D p3 = Vector3D::point(-1, 0, 0);points.push_back(p3);
        Vector3D p4 = Vector3D::point(0, -1, 0);points.push_back(p4);
        Vector3D p5 = Vector3D::point(0, 0, -1);points.push_back(p5);
        Vector3D p6 = Vector3D::point(0, 0, 1);points.push_back(p6);

        Face f1; f1.point_indexes = {0,1,5,0};faces.push_back(f1);
        Face f2; f2.point_indexes = {1,2,5,1};faces.push_back(f2);
        Face f3; f3.point_indexes = {2,3,5,2};faces.push_back(f3);
        Face f4; f4.point_indexes = {3,0,5,3};faces.push_back(f4);
        Face f5; f5.point_indexes = {1,0,4,1};faces.push_back(f5);
        Face f6; f6.point_indexes = {2,1,4,2};faces.push_back(f6);
        Face f7; f7.point_indexes = {3,2,4,3};faces.push_back(f7);
        Face f8; f8.point_indexes = {0,3,4,0};faces.push_back(f8);

        FigureGenerated = true;
    }
    else{
        cout << "already a figure generated"<<endl;
    }
}

void Figure::createIcosahedron(){
    if (!FigureGenerated) {
        points.clear();points2D.clear();lijnen.clear();faces.clear();

        const double PI = 3.14159265358979323846;
        const double sqrt5_2 = sqrt(5) / 2.0;

        Vector3D p1 = Vector3D::point(0, 0, sqrt5_2);
        points.push_back(p1);

        for (int i = 2; i <= 6; i++) {
            double angle = (i - 2)*2*PI/5;
            Vector3D p = Vector3D::point(cos(angle), sin(angle), 0.5);
            points.push_back(p);
        }

        for (int i = 7; i <= 11; i++) {
            double angle = PI/5 + (i-7)*2*PI/5;
            Vector3D p = Vector3D::point(cos(angle), sin(angle), -0.5);
            points.push_back(p);
        }

        Vector3D p12 = Vector3D::point(0, 0, -sqrt5_2);points.push_back(p12);

        Face f1; f1.point_indexes = {0,1,2,0};faces.push_back(f1);
        Face f2; f2.point_indexes = {0,2,3,0};faces.push_back(f2);
        Face f3; f3.point_indexes = {0,3,4,0};faces.push_back(f3);
        Face f4; f4.point_indexes = {0,4,5,0};faces.push_back(f4);
        Face f5; f5.point_indexes = {0,5,1,0};faces.push_back(f5);
        Face f6; f6.point_indexes = {1,6,2,1};faces.push_back(f6);
        Face f7; f7.point_indexes = {2,6,7,2};faces.push_back(f7);
        Face f8; f8.point_indexes = {2,7,3,2};faces.push_back(f8);
        Face f9; f9.point_indexes = {3,7,8,3};faces.push_back(f9);
        Face f10; f10.point_indexes = {3,8,4,3};faces.push_back(f10);
        Face f11; f11.point_indexes = {4,8,9,4};faces.push_back(f11);
        Face f12; f12.point_indexes = {4,9,5,4};faces.push_back(f12);
        Face f13; f13.point_indexes = {5,9,10,5};faces.push_back(f13);
        Face f14; f14.point_indexes = {5,10,1,5};faces.push_back(f14);
        Face f15; f15.point_indexes = {1,10,6,1};faces.push_back(f15);
        Face f16; f16.point_indexes = {11,7,6,11};faces.push_back(f16);
        Face f17; f17.point_indexes = {11,8,7,11};faces.push_back(f17);
        Face f18; f18.point_indexes = {11,9,8,11};faces.push_back(f18);
        Face f19; f19.point_indexes = {11,10,9,11};faces.push_back(f19);
        Face f20; f20.point_indexes = {11,6,10,11};faces.push_back(f20);


        FigureGenerated = true;
    }
    else{
        cout << "already created a figure" << endl;
    }
}

void Figure::createDodecahedron(){
    if (!FigureGenerated) {
        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        // Create temporary vectors to store icosahedron data
        vector<Vector3D> icosahedronPoints;
        vector<Face> icosahedronFaces;

        const double PI = 3.14159265358979323846;
        const double sqrt5_2 = sqrt(5) / 2.0;

        // Create icosahedron points
        Vector3D p1 = Vector3D::point(0, 0, sqrt5_2);
        icosahedronPoints.push_back(p1);

        for (int i = 2; i <= 6; i++) {
            double angle = (i - 2)*2*PI/5;
            Vector3D p = Vector3D::point(cos(angle), sin(angle), 0.5);
            icosahedronPoints.push_back(p);
        }

        for (int i = 7; i <= 11; i++) {
            double angle = PI/5 + (i-7)*2*PI/5;
            Vector3D p = Vector3D::point(cos(angle), sin(angle), -0.5);
            icosahedronPoints.push_back(p);
        }

        Vector3D p12 = Vector3D::point(0, 0, -sqrt5_2);
        icosahedronPoints.push_back(p12);

        // Define the 20 triangular faces of the icosahedron
        Face f1; f1.point_indexes = {0, 1, 2}; icosahedronFaces.push_back(f1);
        Face f2; f2.point_indexes = {0, 2, 3}; icosahedronFaces.push_back(f2);
        Face f3; f3.point_indexes = {0, 3, 4}; icosahedronFaces.push_back(f3);
        Face f4; f4.point_indexes = {0, 4, 5}; icosahedronFaces.push_back(f4);
        Face f5; f5.point_indexes = {0, 5, 1}; icosahedronFaces.push_back(f5);
        Face f6; f6.point_indexes = {1, 6, 2}; icosahedronFaces.push_back(f6);
        Face f7; f7.point_indexes = {2, 6, 7}; icosahedronFaces.push_back(f7);
        Face f8; f8.point_indexes = {2, 7, 3}; icosahedronFaces.push_back(f8);
        Face f9; f9.point_indexes = {3, 7, 8}; icosahedronFaces.push_back(f9);
        Face f10; f10.point_indexes = {3, 8, 4}; icosahedronFaces.push_back(f10);
        Face f11; f11.point_indexes = {4, 8, 9}; icosahedronFaces.push_back(f11);
        Face f12; f12.point_indexes = {4, 9, 5}; icosahedronFaces.push_back(f12);
        Face f13; f13.point_indexes = {5, 9, 10}; icosahedronFaces.push_back(f13);
        Face f14; f14.point_indexes = {5, 10, 1}; icosahedronFaces.push_back(f14);
        Face f15; f15.point_indexes = {1, 10, 6}; icosahedronFaces.push_back(f15);
        Face f16; f16.point_indexes = {11, 7, 6}; icosahedronFaces.push_back(f16);
        Face f17; f17.point_indexes = {11, 8, 7}; icosahedronFaces.push_back(f17);
        Face f18; f18.point_indexes = {11, 9, 8}; icosahedronFaces.push_back(f18);
        Face f19; f19.point_indexes = {11, 10, 9}; icosahedronFaces.push_back(f19);
        Face f20; f20.point_indexes = {11, 6, 10}; icosahedronFaces.push_back(f20);

        // Now create dodecahedron points from icosahedron faces
        // Each face center of icosahedron becomes a vertex of dodecahedron
        for (auto face: icosahedronFaces) {
            Vector3D point;

            // Calculate face centroid
            point.x = (icosahedronPoints[face.point_indexes[0]].x +
                       icosahedronPoints[face.point_indexes[1]].x +
                       icosahedronPoints[face.point_indexes[2]].x) / 3.0;

            point.y = (icosahedronPoints[face.point_indexes[0]].y +
                       icosahedronPoints[face.point_indexes[1]].y +
                       icosahedronPoints[face.point_indexes[2]].y) / 3.0;

            point.z = (icosahedronPoints[face.point_indexes[0]].z +
                       icosahedronPoints[face.point_indexes[1]].z +
                       icosahedronPoints[face.point_indexes[2]].z) / 3.0;

            point.normalise();
            points.push_back(point);
        }

        // Now define the 12 pentagonal faces of the dodecahedron
        Face pent1; pent1.point_indexes = {0, 1, 2, 3, 4, 0}; faces.push_back(pent1);
        Face pent2; pent2.point_indexes = {0, 5, 6, 7, 1, 0}; faces.push_back(pent2);
        Face pent3; pent3.point_indexes = {1, 7, 8, 9, 2, 1}; faces.push_back(pent3);
        Face pent4; pent4.point_indexes = {2, 9, 10, 11, 3, 2}; faces.push_back(pent4);
        Face pent5; pent5.point_indexes = {3, 11, 12, 13, 4, 3}; faces.push_back(pent5);
        Face pent6; pent6.point_indexes = {4, 13, 14, 5, 0, 4}; faces.push_back(pent6);
        Face pent7; pent7.point_indexes = {19, 18, 17, 16, 15, 19}; faces.push_back(pent7);
        Face pent8; pent8.point_indexes = {19, 14, 13, 12, 18, 19}; faces.push_back(pent8);
        Face pent9; pent9.point_indexes = {18, 12, 11, 10, 17, 18}; faces.push_back(pent9);
        Face pent10; pent10.point_indexes = {17, 10, 9, 8, 16, 17}; faces.push_back(pent10);
        Face pent11; pent11.point_indexes = {16, 8, 7, 6, 15, 16}; faces.push_back(pent11);
        Face pent12; pent12.point_indexes = {15, 6, 5, 14, 19, 15}; faces.push_back(pent12);

        FigureGenerated = true;
    }
    else {
        cout << "already created a figure" << endl;
    }
}

void Figure::createCylinder(const int &n, const double &h) {
    if (!FigureGenerated) {
        const double PI = 3.14159265358979323846;

        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        // Create bottom circle points
        for (int i = 0; i < n; i++) {
            Vector3D p;
            p.x = cos(2 * i * PI / n);
            p.y = sin(2 * i * PI / n);
            p.z = 0;
            points.push_back(p);
        }

        // Create top circle points
        for (int i = 0; i < n; i++) {
            Vector3D p;
            p.x = cos(2 * i * PI / n);
            p.y = sin(2 * i * PI / n);
            p.z = h;
            points.push_back(p);
        }

        // Create bottom face
        Face bottom;
        for (int i = 0; i < n; i++) {
            bottom.point_indexes.push_back(i);
        }
        bottom.point_indexes.push_back(0);
        faces.push_back(bottom);

        // Create top face
        Face top;
        for (int i = 0; i < n; i++) {
            top.point_indexes.push_back(n + i);
        }
        top.point_indexes.push_back(n);
        faces.push_back(top);

        for (int i = 0; i < n; i++) {
            Face rect;
            rect.point_indexes.push_back(i);
            rect.point_indexes.push_back((i + 1) % n);
            rect.point_indexes.push_back(n + (i + 1) % n);
            rect.point_indexes.push_back(n + i);
            rect.point_indexes.push_back(i);
            faces.push_back(rect);
        }

        FigureGenerated = true;
    }
    else {
        cout << "already a figure generated" << endl;
    }
}

void Figure::createKegel(const int &n, const double &h) {
    if (!FigureGenerated) {
        const double PI = 3.14159265358979323846;

        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        // Create base circle points
        for (int i = 0; i < n; i++) {
            Vector3D p;
            p.x = cos(2 * i * PI / n);
            p.y = sin(2 * i * PI / n);
            p.z = 0;
            points.push_back(p); // Add point to the vector
        }

        // Create top point
        Vector3D top;
        top.x = 0;
        top.y = 0;
        top.z = h;
        points.push_back(top); // Add top point to vector
        int topIndex = points.size() - 1; // Index of the top point

        // Create base face (for the circle base)
        Face base;
        for (int i = 0; i < n; i++) {
            base.point_indexes.push_back(i);
        }
        base.point_indexes.push_back(0); // Close the loop
        faces.push_back(base);

        // Create triangular faces connecting base to top
        for (int i = 0; i < n; i++) {
            Face triangle;
            triangle.point_indexes.push_back(i);
            triangle.point_indexes.push_back((i + 1) % n); // Next point, with wrap-around
            triangle.point_indexes.push_back(topIndex);     // Top point
            triangle.point_indexes.push_back(i);            // Close the loop
            faces.push_back(triangle);
        }

        FigureGenerated = true;
    }
    else {
        cout << "already a figure generated" << endl;
    }
}

void Figure::createSphere(const int &n) {
    if(!FigureGenerated) {

        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        Figure icosahedron;
        icosahedron.createIcosahedron();

        std::vector<Vector3D> sphPoints = icosahedron.points;
        std::vector<Face> sphFaces = icosahedron.faces;

        //hoeveel keer delen
        for (int i = 0; i < n; i++) {
            vector<Face> newFaces;
            vector<Vector3D> newPoints;
            int indexFromBegin = -1;

            //driehoeken delen
            for (auto f: sphFaces) {
                Vector3D A = sphPoints.at(f.point_indexes.at(0));
                Vector3D B = sphPoints.at(f.point_indexes.at(1));
                Vector3D C = sphPoints.at(f.point_indexes.at(2));

                Vector3D D;
                Vector3D E;
                Vector3D F;

                D.x = (A.x + B.x) / 2;
                D.y = (A.y + B.y) / 2;
                D.z = (A.z + B.z) / 2;

                E.x = (A.x + C.x) / 2;
                E.y = (A.y + C.y) / 2;
                E.z = (A.z + C.z) / 2;

                F.x = (B.x + C.x) / 2;
                F.y = (B.y + C.y) / 2;
                F.z = (B.z + C.z) / 2;

                A.normalise();
                B.normalise();
                C.normalise();
                D.normalise();
                E.normalise();
                F.normalise();

                newPoints.push_back(A);
                newPoints.push_back(B);
                newPoints.push_back(C);
                newPoints.push_back(D);
                newPoints.push_back(E);
                newPoints.push_back(F);
                indexFromBegin += 6;

                Face f1;
                f1.point_indexes.push_back(indexFromBegin - 5);
                f1.point_indexes.push_back(indexFromBegin - 2);
                f1.point_indexes.push_back(indexFromBegin - 1);
                f1.point_indexes.push_back(indexFromBegin - 5);

                Face f2;
                f2.point_indexes.push_back(indexFromBegin - 4);
                f2.point_indexes.push_back(indexFromBegin);
                f2.point_indexes.push_back(indexFromBegin - 2);
                f2.point_indexes.push_back(indexFromBegin - 4);

                Face f3;
                f3.point_indexes.push_back(indexFromBegin - 3);
                f3.point_indexes.push_back(indexFromBegin - 1);
                f3.point_indexes.push_back(indexFromBegin);
                f3.point_indexes.push_back(indexFromBegin - 3);

                Face f4;
                f4.point_indexes.push_back(indexFromBegin - 2);
                f4.point_indexes.push_back(indexFromBegin);
                f4.point_indexes.push_back(indexFromBegin - 1);
                f4.point_indexes.push_back(indexFromBegin - 2);

                newFaces.push_back(f1);
                newFaces.push_back(f2);
                newFaces.push_back(f3);
                newFaces.push_back(f4);

            }
            sphFaces.clear();
            sphPoints.clear();
            sphFaces = newFaces;
            sphPoints = newPoints;
        }
        points = sphPoints;
        faces = sphFaces;
        FigureGenerated = true;
    }
    else {
        cout << "already a figure generated"<<endl;
    }
}

void Figure::createTorus(const double &r, const double &R, const int &n, const int &m) {
    const double PI = 3.14159265358979323846;

    //generating the circle faces first
    for (int i = 0; i < n; i++){
        Face circle;
        double firstPointOfCircle;
        for (int j = 0; j < m; j++){
            double u = (2*i*PI)/n;
            double v = (2*j*PI)/m;

            Vector3D Punt;
            Punt.x = ((R + r*cos(v))*cos(u));
            Punt.y = ((R + r*cos(v))* sin(u));
            Punt.z = r* sin(v);

            points.push_back(Punt);
            double pointPositionInVector = i*m + j;
            if(j ==0){
                firstPointOfCircle = pointPositionInVector;
            }
            circle.point_indexes.push_back(pointPositionInVector);
        }
        circle.point_indexes.push_back(firstPointOfCircle);
        faces.push_back(circle);
    }
    for (int i = 0; i<n; i++){
        Face face1 = faces[i];
        Face face2;
        if(i != n-1){
            face2 = faces[i+1];
        }
        else{
            face2 = faces[0];
        }

        for (int j = 0; j < m; ++j) {
            Face rect;
            int p1 = face1.point_indexes[j];
            int p2 = face2.point_indexes[j];
            int p3 = face2.point_indexes[j+1];
            int p4 = face1.point_indexes[j+1];
            rect.point_indexes.push_back(p1);
            rect.point_indexes.push_back(p2);
            rect.point_indexes.push_back(p3);
            rect.point_indexes.push_back(p4);
            rect.point_indexes.push_back(p1);
            faces.push_back(rect);
        }
    }
}

void Figure::Trainguleer() {
     vector<Face> newTFaces;
     for(auto f: this->faces){
         for (int i = 0; i<f.point_indexes.size()-3;i++){
             Face fi;
             fi.point_indexes.push_back(f.point_indexes[0]);
             fi.point_indexes.push_back(f.point_indexes[i+1]);
             fi.point_indexes.push_back(f.point_indexes[i+2]);
             fi.point_indexes.push_back(f.point_indexes[0]);
             newTFaces.push_back(fi);
         }
     }
     this->faces.clear();
     this->faces = newTFaces;
}

=======
//
// Created by yaman haj ahmad on 19/03/2025.
//

#include "Figure.h"
#include <iostream>
#include <cmath>

//dit functie spreekt voor zich, 2 punten (van de lines van line2d files/de lsystemen stuk) zullen met elkaar verbonden worden in een
//2d image.
void Figure::point2dTOline2d() {
    //elk face hier bevat maar 2 punten (eigenlijk index van 2 punten in points2D vector). (om lijn te maken)
    for (auto face: faces) {
        Line2D lijn;
        pair<int,int> check = {face.point_indexes.at(0),face.point_indexes.at(1)};
        pair<int,int> check2 = {face.point_indexes.at(1),face.point_indexes.at(0)};
        if (LinesDone.find(check) != LinesDone.end() or LinesDone.find(check2) != LinesDone.end()) {
            continue;
        }
        else {
            lijn.p1 = points2D.at(face.point_indexes.at(0));
            lijn.p2 = points2D.at(face.point_indexes.at(1));
            lijn.color = color;

            //z1 en z2 zijn de z cordinaten opgeslagen om met zbuffering te werken in het geval van zbuffering.
            lijn.z1 = points.at(face.point_indexes.at(0)).z;
            lijn.z2 = points.at(face.point_indexes.at(1)).z;
            lijnen.push_back(lijn);
        }
    }
}


void Figure::figurePointsToLine2d() {
    //faces hier kan zo veel punten bevatten (eigenlijk daarmee bedoel ik de index van punten in points2D vector)
    for (auto face: faces){
        //voor het itereren moet ik kijken hoeveel indexen in de face vector zitten.
        int i_max = face.point_indexes.size();

        //ik ga genoeg itereren om alles in te lezen
        for (int i = 0; i<i_max-1; i++){
            Line2D lijn;
            pair<int,int> check = {face.point_indexes.at(i),face.point_indexes.at(i+1)};
            pair<int,int> check2 = {face.point_indexes.at(i+1),face.point_indexes.at(i)};
            if (LinesDone.find(check) != LinesDone.end() or LinesDone.find(check2) != LinesDone.end()) {
                continue;
            }
            else {
                lijn.p1 = points2D.at(face.point_indexes.at(i));
                lijn.p2 = points2D.at(face.point_indexes.at(i + 1));
                lijn.color = color;

                //de z cordinaten van de 3d punten opslaan om later met zbuffering te werken wanneer het moet.
                lijn.z1 = points.at(face.point_indexes.at(i)).z;
                lijn.z2 = points.at(face.point_indexes.at(i + 1)).z;

                lijnen.push_back(lijn);
            }
        }
    }
}
/*
    alle figuren zijn basically hardcoded op basis van wat in de cursus stond.
*/
void Figure::createTetrahedron(){
    if (!FigureGenerated){
        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        Vector3D p1 = Vector3D::point(1,-1,-1);
        Vector3D p2 = Vector3D::point(-1,1,-1);
        Vector3D p3 = Vector3D::point(1,1,1);
        Vector3D p4 = Vector3D::point(-1,-1,1);

        points.push_back(p1); points.push_back(p2); points.push_back(p3); points.push_back(p4);

        Face f1; f1.point_indexes = {0,1,2,0};faces.push_back(f1);
        Face f2; f2.point_indexes = {1,3,2,1};faces.push_back(f2);
        Face f3; f3.point_indexes = {0,3,1,0};faces.push_back(f3);
        Face f4; f4.point_indexes = {0,2,3,0};faces.push_back(f4);

        FigureGenerated = true;
    }
    else{
        cout << "already a figure generated"<<endl;
    }
}

void Figure::createCube() {
    if (!FigureGenerated) {
        points.clear();points2D.clear();lijnen.clear();faces.clear();

        Vector3D p1 = Vector3D::point(1, -1, -1);points.push_back(p1);
        Vector3D p2 = Vector3D::point(-1, 1, -1);points.push_back(p2);
        Vector3D p3 = Vector3D::point(1, 1, 1);points.push_back(p3);
        Vector3D p4 = Vector3D::point(-1, -1, 1);points.push_back(p4);
        Vector3D p5 = Vector3D::point(1, 1, -1);points.push_back(p5);
        Vector3D p6 = Vector3D::point(-1, -1, -1);points.push_back(p6);
        Vector3D p7 = Vector3D::point(1, -1, 1);points.push_back(p7);
        Vector3D p8 = Vector3D::point(-1, 1, 1);points.push_back(p8);


        Face f1; f1.point_indexes = {0,4,2,6,0};faces.push_back(f1);
        Face f2; f2.point_indexes = {4,1,7,2,4};faces.push_back(f2);
        Face f3; f3.point_indexes = {1,5,3,7,1};faces.push_back(f3);
        Face f4; f4.point_indexes = {5,0,6,3,5};faces.push_back(f4);
        Face f5; f5.point_indexes = {6,2,7,3,6};faces.push_back(f5);
        Face f6; f6.point_indexes = {0,5,1,4,0};faces.push_back(f6);

        FigureGenerated = true;
    }
    else{
        cout << "already a figure generated"<<endl;
    }
}

void Figure::creatOctahedron() {
    if (!FigureGenerated) {
        points.clear();points2D.clear();lijnen.clear();faces.clear();

        Vector3D p1 = Vector3D::point(1, 0, 0);points.push_back(p1);
        Vector3D p2 = Vector3D::point(0, 1, 0);points.push_back(p2);
        Vector3D p3 = Vector3D::point(-1, 0, 0);points.push_back(p3);
        Vector3D p4 = Vector3D::point(0, -1, 0);points.push_back(p4);
        Vector3D p5 = Vector3D::point(0, 0, -1);points.push_back(p5);
        Vector3D p6 = Vector3D::point(0, 0, 1);points.push_back(p6);

        Face f1; f1.point_indexes = {0,1,5,0};faces.push_back(f1);
        Face f2; f2.point_indexes = {1,2,5,1};faces.push_back(f2);
        Face f3; f3.point_indexes = {2,3,5,2};faces.push_back(f3);
        Face f4; f4.point_indexes = {3,0,5,3};faces.push_back(f4);
        Face f5; f5.point_indexes = {1,0,4,1};faces.push_back(f5);
        Face f6; f6.point_indexes = {2,1,4,2};faces.push_back(f6);
        Face f7; f7.point_indexes = {3,2,4,3};faces.push_back(f7);
        Face f8; f8.point_indexes = {0,3,4,0};faces.push_back(f8);

        FigureGenerated = true;
    }
    else{
        cout << "already a figure generated"<<endl;
    }
}

void Figure::createIcosahedron(){
    if (!FigureGenerated) {
        points.clear();points2D.clear();lijnen.clear();faces.clear();

        const double PI = 3.14159265358979323846;
        const double sqrt5_2 = sqrt(5) / 2.0;

        Vector3D p1 = Vector3D::point(0, 0, sqrt5_2);
        points.push_back(p1);

        for (int i = 2; i <= 6; i++) {
            double angle = (i - 2)*2*PI/5;
            Vector3D p = Vector3D::point(cos(angle), sin(angle), 0.5);
            points.push_back(p);
        }

        for (int i = 7; i <= 11; i++) {
            double angle = PI/5 + (i-7)*2*PI/5;
            Vector3D p = Vector3D::point(cos(angle), sin(angle), -0.5);
            points.push_back(p);
        }

        Vector3D p12 = Vector3D::point(0, 0, -sqrt5_2);points.push_back(p12);

        Face f1; f1.point_indexes = {0,1,2,0};faces.push_back(f1);
        Face f2; f2.point_indexes = {0,2,3,0};faces.push_back(f2);
        Face f3; f3.point_indexes = {0,3,4,0};faces.push_back(f3);
        Face f4; f4.point_indexes = {0,4,5,0};faces.push_back(f4);
        Face f5; f5.point_indexes = {0,5,1,0};faces.push_back(f5);
        Face f6; f6.point_indexes = {1,6,2,1};faces.push_back(f6);
        Face f7; f7.point_indexes = {2,6,7,2};faces.push_back(f7);
        Face f8; f8.point_indexes = {2,7,3,2};faces.push_back(f8);
        Face f9; f9.point_indexes = {3,7,8,3};faces.push_back(f9);
        Face f10; f10.point_indexes = {3,8,4,3};faces.push_back(f10);
        Face f11; f11.point_indexes = {4,8,9,4};faces.push_back(f11);
        Face f12; f12.point_indexes = {4,9,5,4};faces.push_back(f12);
        Face f13; f13.point_indexes = {5,9,10,5};faces.push_back(f13);
        Face f14; f14.point_indexes = {5,10,1,5};faces.push_back(f14);
        Face f15; f15.point_indexes = {1,10,6,1};faces.push_back(f15);
        Face f16; f16.point_indexes = {11,7,6,11};faces.push_back(f16);
        Face f17; f17.point_indexes = {11,8,7,11};faces.push_back(f17);
        Face f18; f18.point_indexes = {11,9,8,11};faces.push_back(f18);
        Face f19; f19.point_indexes = {11,10,9,11};faces.push_back(f19);
        Face f20; f20.point_indexes = {11,6,10,11};faces.push_back(f20);


        FigureGenerated = true;
    }
    else{
        cout << "already created a figure" << endl;
    }
}

void Figure::createDodecahedron(){
    if (!FigureGenerated) {
        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        // Create temporary vectors to store icosahedron data
        vector<Vector3D> icosahedronPoints;
        vector<Face> icosahedronFaces;

        const double PI = 3.14159265358979323846;
        const double sqrt5_2 = sqrt(5) / 2.0;

        // Create icosahedron points
        Vector3D p1 = Vector3D::point(0, 0, sqrt5_2);
        icosahedronPoints.push_back(p1);

        for (int i = 2; i <= 6; i++) {
            double angle = (i - 2)*2*PI/5;
            Vector3D p = Vector3D::point(cos(angle), sin(angle), 0.5);
            icosahedronPoints.push_back(p);
        }

        for (int i = 7; i <= 11; i++) {
            double angle = PI/5 + (i-7)*2*PI/5;
            Vector3D p = Vector3D::point(cos(angle), sin(angle), -0.5);
            icosahedronPoints.push_back(p);
        }

        Vector3D p12 = Vector3D::point(0, 0, -sqrt5_2);
        icosahedronPoints.push_back(p12);

        // Define the 20 triangular faces of the icosahedron
        Face f1; f1.point_indexes = {0, 1, 2}; icosahedronFaces.push_back(f1);
        Face f2; f2.point_indexes = {0, 2, 3}; icosahedronFaces.push_back(f2);
        Face f3; f3.point_indexes = {0, 3, 4}; icosahedronFaces.push_back(f3);
        Face f4; f4.point_indexes = {0, 4, 5}; icosahedronFaces.push_back(f4);
        Face f5; f5.point_indexes = {0, 5, 1}; icosahedronFaces.push_back(f5);
        Face f6; f6.point_indexes = {1, 6, 2}; icosahedronFaces.push_back(f6);
        Face f7; f7.point_indexes = {2, 6, 7}; icosahedronFaces.push_back(f7);
        Face f8; f8.point_indexes = {2, 7, 3}; icosahedronFaces.push_back(f8);
        Face f9; f9.point_indexes = {3, 7, 8}; icosahedronFaces.push_back(f9);
        Face f10; f10.point_indexes = {3, 8, 4}; icosahedronFaces.push_back(f10);
        Face f11; f11.point_indexes = {4, 8, 9}; icosahedronFaces.push_back(f11);
        Face f12; f12.point_indexes = {4, 9, 5}; icosahedronFaces.push_back(f12);
        Face f13; f13.point_indexes = {5, 9, 10}; icosahedronFaces.push_back(f13);
        Face f14; f14.point_indexes = {5, 10, 1}; icosahedronFaces.push_back(f14);
        Face f15; f15.point_indexes = {1, 10, 6}; icosahedronFaces.push_back(f15);
        Face f16; f16.point_indexes = {11, 7, 6}; icosahedronFaces.push_back(f16);
        Face f17; f17.point_indexes = {11, 8, 7}; icosahedronFaces.push_back(f17);
        Face f18; f18.point_indexes = {11, 9, 8}; icosahedronFaces.push_back(f18);
        Face f19; f19.point_indexes = {11, 10, 9}; icosahedronFaces.push_back(f19);
        Face f20; f20.point_indexes = {11, 6, 10}; icosahedronFaces.push_back(f20);

        // Now create dodecahedron points from icosahedron faces
        // Each face center of icosahedron becomes a vertex of dodecahedron
        for (auto face: icosahedronFaces) {
            Vector3D point;

            // Calculate face centroid
            point.x = (icosahedronPoints[face.point_indexes[0]].x +
                       icosahedronPoints[face.point_indexes[1]].x +
                       icosahedronPoints[face.point_indexes[2]].x) / 3.0;

            point.y = (icosahedronPoints[face.point_indexes[0]].y +
                       icosahedronPoints[face.point_indexes[1]].y +
                       icosahedronPoints[face.point_indexes[2]].y) / 3.0;

            point.z = (icosahedronPoints[face.point_indexes[0]].z +
                       icosahedronPoints[face.point_indexes[1]].z +
                       icosahedronPoints[face.point_indexes[2]].z) / 3.0;

            point.normalise();
            points.push_back(point);
        }

        // Now define the 12 pentagonal faces of the dodecahedron
        Face pent1; pent1.point_indexes = {0, 1, 2, 3, 4, 0}; faces.push_back(pent1);
        Face pent2; pent2.point_indexes = {0, 5, 6, 7, 1, 0}; faces.push_back(pent2);
        Face pent3; pent3.point_indexes = {1, 7, 8, 9, 2, 1}; faces.push_back(pent3);
        Face pent4; pent4.point_indexes = {2, 9, 10, 11, 3, 2}; faces.push_back(pent4);
        Face pent5; pent5.point_indexes = {3, 11, 12, 13, 4, 3}; faces.push_back(pent5);
        Face pent6; pent6.point_indexes = {4, 13, 14, 5, 0, 4}; faces.push_back(pent6);
        Face pent7; pent7.point_indexes = {19, 18, 17, 16, 15, 19}; faces.push_back(pent7);
        Face pent8; pent8.point_indexes = {19, 14, 13, 12, 18, 19}; faces.push_back(pent8);
        Face pent9; pent9.point_indexes = {18, 12, 11, 10, 17, 18}; faces.push_back(pent9);
        Face pent10; pent10.point_indexes = {17, 10, 9, 8, 16, 17}; faces.push_back(pent10);
        Face pent11; pent11.point_indexes = {16, 8, 7, 6, 15, 16}; faces.push_back(pent11);
        Face pent12; pent12.point_indexes = {15, 6, 5, 14, 19, 15}; faces.push_back(pent12);

        FigureGenerated = true;
    }
    else {
        cout << "already created a figure" << endl;
    }
}

void Figure::createCylinder(const int &n, const double &h) {
    if (!FigureGenerated) {
        const double PI = 3.14159265358979323846;

        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        // Create bottom circle points
        for (int i = 0; i < n; i++) {
            Vector3D p;
            p.x = cos(2 * i * PI / n);
            p.y = sin(2 * i * PI / n);
            p.z = 0;
            points.push_back(p);
        }

        // Create top circle points
        for (int i = 0; i < n; i++) {
            Vector3D p;
            p.x = cos(2 * i * PI / n);
            p.y = sin(2 * i * PI / n);
            p.z = h;
            points.push_back(p);
        }

        // Create bottom face
        Face bottom;
        for (int i = 0; i < n; i++) {
            bottom.point_indexes.push_back(i);
        }
        bottom.point_indexes.push_back(0);
        faces.push_back(bottom);

        // Create top face
        Face top;
        for (int i = 0; i < n; i++) {
            top.point_indexes.push_back(n + i);
        }
        top.point_indexes.push_back(n);
        faces.push_back(top);

        for (int i = 0; i < n; i++) {
            Face rect;
            rect.point_indexes.push_back(i);
            rect.point_indexes.push_back((i + 1) % n);
            rect.point_indexes.push_back(n + (i + 1) % n);
            rect.point_indexes.push_back(n + i);
            rect.point_indexes.push_back(i);
            faces.push_back(rect);
        }

        FigureGenerated = true;
    }
    else {
        cout << "already a figure generated" << endl;
    }
}

void Figure::createKegel(const int &n, const double &h) {
    if (!FigureGenerated) {
        const double PI = 3.14159265358979323846;

        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        // Create base circle points
        for (int i = 0; i < n; i++) {
            Vector3D p;
            p.x = cos(2 * i * PI / n);
            p.y = sin(2 * i * PI / n);
            p.z = 0;
            points.push_back(p); // Add point to the vector
        }

        // Create top point
        Vector3D top;
        top.x = 0;
        top.y = 0;
        top.z = h;
        points.push_back(top); // Add top point to vector
        int topIndex = points.size() - 1; // Index of the top point

        // Create base face (for the circle base)
        Face base;
        for (int i = 0; i < n; i++) {
            base.point_indexes.push_back(i);
        }
        base.point_indexes.push_back(0); // Close the loop
        faces.push_back(base);

        // Create triangular faces connecting base to top
        for (int i = 0; i < n; i++) {
            Face triangle;
            triangle.point_indexes.push_back(i);
            triangle.point_indexes.push_back((i + 1) % n); // Next point, with wrap-around
            triangle.point_indexes.push_back(topIndex);     // Top point
            triangle.point_indexes.push_back(i);            // Close the loop
            faces.push_back(triangle);
        }

        FigureGenerated = true;
    }
    else {
        cout << "already a figure generated" << endl;
    }
}

void Figure::createSphere(const int &n) {
    if(!FigureGenerated) {

        points.clear();
        points2D.clear();
        lijnen.clear();
        faces.clear();

        Figure icosahedron;
        icosahedron.createIcosahedron();

        std::vector<Vector3D> sphPoints = icosahedron.points;
        std::vector<Face> sphFaces = icosahedron.faces;

        //hoeveel keer delen
        for (int i = 0; i < n; i++) {
            vector<Face> newFaces;
            vector<Vector3D> newPoints;
            int indexFromBegin = -1;

            //driehoeken delen
            for (auto f: sphFaces) {
                Vector3D A = sphPoints.at(f.point_indexes.at(0));
                Vector3D B = sphPoints.at(f.point_indexes.at(1));
                Vector3D C = sphPoints.at(f.point_indexes.at(2));

                Vector3D D;
                Vector3D E;
                Vector3D F;

                D.x = (A.x + B.x) / 2;
                D.y = (A.y + B.y) / 2;
                D.z = (A.z + B.z) / 2;

                E.x = (A.x + C.x) / 2;
                E.y = (A.y + C.y) / 2;
                E.z = (A.z + C.z) / 2;

                F.x = (B.x + C.x) / 2;
                F.y = (B.y + C.y) / 2;
                F.z = (B.z + C.z) / 2;

                A.normalise();
                B.normalise();
                C.normalise();
                D.normalise();
                E.normalise();
                F.normalise();

                newPoints.push_back(A);
                newPoints.push_back(B);
                newPoints.push_back(C);
                newPoints.push_back(D);
                newPoints.push_back(E);
                newPoints.push_back(F);
                indexFromBegin += 6;

                Face f1;
                f1.point_indexes.push_back(indexFromBegin - 5);
                f1.point_indexes.push_back(indexFromBegin - 2);
                f1.point_indexes.push_back(indexFromBegin - 1);
                f1.point_indexes.push_back(indexFromBegin - 5);

                Face f2;
                f2.point_indexes.push_back(indexFromBegin - 4);
                f2.point_indexes.push_back(indexFromBegin);
                f2.point_indexes.push_back(indexFromBegin - 2);
                f2.point_indexes.push_back(indexFromBegin - 4);

                Face f3;
                f3.point_indexes.push_back(indexFromBegin - 3);
                f3.point_indexes.push_back(indexFromBegin - 1);
                f3.point_indexes.push_back(indexFromBegin);
                f3.point_indexes.push_back(indexFromBegin - 3);

                Face f4;
                f4.point_indexes.push_back(indexFromBegin - 2);
                f4.point_indexes.push_back(indexFromBegin);
                f4.point_indexes.push_back(indexFromBegin - 1);
                f4.point_indexes.push_back(indexFromBegin - 2);

                newFaces.push_back(f1);
                newFaces.push_back(f2);
                newFaces.push_back(f3);
                newFaces.push_back(f4);

            }
            sphFaces.clear();
            sphPoints.clear();
            sphFaces = newFaces;
            sphPoints = newPoints;
        }
        points = sphPoints;
        faces = sphFaces;
        FigureGenerated = true;
    }
    else {
        cout << "already a figure generated"<<endl;
    }
}

void Figure::createTorus(const double &r, const double &R, const int &n, const int &m) {
    const double PI = 3.14159265358979323846;

    //generating the circle faces first
    for (int i = 0; i < n; i++){
        Face circle;
        double firstPointOfCircle;
        for (int j = 0; j < m; j++){
            double u = (2*i*PI)/n;
            double v = (2*j*PI)/m;

            Vector3D Punt;
            Punt.x = ((R + r*cos(v))*cos(u));
            Punt.y = ((R + r*cos(v))* sin(u));
            Punt.z = r* sin(v);

            points.push_back(Punt);
            double pointPositionInVector = i*m + j;
            if(j ==0){
                firstPointOfCircle = pointPositionInVector;
            }
            circle.point_indexes.push_back(pointPositionInVector);
        }
        circle.point_indexes.push_back(firstPointOfCircle);
        faces.push_back(circle);
    }
    for (int i = 0; i<n; i++){
        Face face1 = faces[i];
        Face face2;
        if(i != n-1){
            face2 = faces[i+1];
        }
        else{
            face2 = faces[0];
        }

        for (int j = 0; j < m; ++j) {
            Face rect;
            int p1 = face1.point_indexes[j];
            int p2 = face2.point_indexes[j];
            int p3 = face2.point_indexes[j+1];
            int p4 = face1.point_indexes[j+1];
            rect.point_indexes.push_back(p1);
            rect.point_indexes.push_back(p2);
            rect.point_indexes.push_back(p3);
            rect.point_indexes.push_back(p4);
            rect.point_indexes.push_back(p1);
            faces.push_back(rect);
        }
    }
}

void Figure::Trainguleer() {
     vector<Face> newTFaces;
     for(auto f: this->faces){
         for (int i = 0; i<f.point_indexes.size()-3;i++){
             Face fi;
             fi.point_indexes.push_back(f.point_indexes[0]);
             fi.point_indexes.push_back(f.point_indexes[i+1]);
             fi.point_indexes.push_back(f.point_indexes[i+2]);
             fi.point_indexes.push_back(f.point_indexes[0]);
             newTFaces.push_back(fi);
         }
     }
     this->faces.clear();
     this->faces = newTFaces;
}

>>>>>>> 03127fb (Initial commit)
