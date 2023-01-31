SPDX_CONVERTER: 
	g++ src/JsonToSpdxConverter.cpp src/input/DateTime.cpp src/input/JsonDocument.cpp src/output/Package.cpp src/output/SpdxDocument.cpp src/output/SpdxDocumentHeader.cpp -o run