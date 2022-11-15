#pragma once
#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkProperty.h>
#include <vtkSmartPointer.h>
#include <vtkXMLUnstructuredGridReader.h>


static vtkSmartPointer<vtkActor> SetupVtuDemoPipeline()
{

  std::string filename("d:/iso1/beam-160k-0-005.odb_1_36.vtu");

  // read all the data from the file
  vtkNew<vtkXMLUnstructuredGridReader> reader;
  reader->SetFileName(filename.c_str());
  reader->Update();

  vtkNew<vtkNamedColors> colors;

  // Create a mapper and actor
  vtkNew<vtkDataSetMapper> mapper;
  mapper->SetInputConnection(reader->GetOutputPort());
  mapper->ScalarVisibilityOff();

  vtkNew<vtkActor> actor;
  actor->SetMapper(mapper);
  actor->GetProperty()->EdgeVisibilityOn();
  actor->GetProperty()->SetLineWidth(2.0);
  actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());

  vtkNew<vtkProperty> backFace;
  backFace->SetColor(colors->GetColor3d("Tomato").GetData());
  actor->SetBackfaceProperty(backFace);

  return actor;
}