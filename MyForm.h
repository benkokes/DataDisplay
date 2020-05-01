#pragma once

#define _USE_MATH_DEFINES
#include "math.h"
#include "stdint.h"
#include <windows.h>

#define NUM_DATA_SOURCES (4)

namespace DataDisplay {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
	using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::IO::Ports; 
	//using namespace OpenGLForm;
	using namespace System::Threading;
	using namespace System::ComponentModel;
	using namespace System::Text;
	// <summary>
    // Summary for MyForm
    // </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
			packet_len = 0;
			input_queue = gcnew System::Collections::Generic::Queue<array<uint8_t>^>();
            InitializeComponent();
			populatePortList();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
			try {
				if (input_port != nullptr && input_port->IsOpen)
					input_port->Close();
			}
			finally {
			}
            if (components)
            {
                delete components;
            }
        }
    private: System::ComponentModel::IContainer^  components;
    protected:

    private:
		System::Collections::Generic::Queue<array<uint8_t>^>^ input_queue;
		array<uint8_t>^ input_array;
		int packet_len;
        /// <summary>
        /// Required designer variable.
        /// </summary>

	public: System::IO::Ports::SerialPort^ input_port;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
    private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart4;
			 Stream^ logFileStream;
			 StreamWriter^ logWriter;
	private: System::Windows::Forms::Button^  open_log_button;
	private: System::Windows::Forms::Button^  close_log_button;
	private: System::Windows::Forms::ComboBox^  comboBoxSerialPortName;

	private: System::Windows::Forms::Button^  openPortButton;
			 System::Windows::Forms::Timer^  timer1;

#pragma region Windows Form Designer generated code
        /// <summary>
            /// Required method for Designer support - do not modify
            /// the contents of this method with the code editor.
            /// </summary>
            void InitializeComponent(void)
            {
				this->components = (gcnew System::ComponentModel::Container());
				System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
				System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
				System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
				System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
				System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
				System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
				System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
				System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
				System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
				this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
				this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
				this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
				this->chart4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
				this->open_log_button = (gcnew System::Windows::Forms::Button());
				this->close_log_button = (gcnew System::Windows::Forms::Button());
				this->comboBoxSerialPortName = (gcnew System::Windows::Forms::ComboBox());
				this->openPortButton = (gcnew System::Windows::Forms::Button());
				this->input_port = (gcnew System::IO::Ports::SerialPort(this->components));
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->BeginInit();
				this->SuspendLayout();
				// 
				// timer1
				// 
				this->timer1->Enabled = true;
				this->timer1->Interval = 30;
				this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
				// 
				// chart1
				// 
				chartArea1->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
				chartArea1->AxisX->Maximum = 400;
				chartArea1->AxisX->Minimum = 0;
				chartArea1->AxisX2->Maximum = 400;
				chartArea1->AxisX2->Minimum = 0;
				chartArea1->AxisY->Title = L"TBD";
				chartArea1->AxisY->ToolTip = L"tbd";
				chartArea1->Name = L"ChartArea1";
				this->chart1->ChartAreas->Add(chartArea1);
				legend1->Name = L"Legend1";
				legend1->Title = L"Sensor1";
				this->chart1->Legends->Add(legend1);
				this->chart1->Location = System::Drawing::Point(340, 10);
				this->chart1->Name = L"chart1";
				series1->ChartArea = L"ChartArea1";
				series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				series1->Legend = L"Legend1";
				series1->LegendText = L"Data";
				series1->LegendToolTip = L" ";
				series1->Name = L"series_axis_x";
				this->chart1->Series->Add(series1);
				this->chart1->Size = System::Drawing::Size(800, 100);
				this->chart1->TabIndex = 0;
				this->chart1->Text = L"chart1";
				// 
				// chart2
				// 
				chartArea2->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
				chartArea2->AxisX->Maximum = 400;
				chartArea2->AxisX->Minimum = 0;
				chartArea2->AxisX->ToolTip = L"Sample Number";
				chartArea2->AxisY->Title = L"TBD";
				chartArea2->AxisY->ToolTip = L" ";
				chartArea2->Name = L"ChartArea1";
				this->chart2->ChartAreas->Add(chartArea2);
				legend2->Name = L"Legend1";
				legend2->Title = L"Sensor2";
				this->chart2->Legends->Add(legend2);
				this->chart2->Location = System::Drawing::Point(340, 120);
				this->chart2->Name = L"chart2";
				series2->ChartArea = L"ChartArea1";
				series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				series2->Legend = L"Legend1";
				series2->LegendText = L"Data";
				series2->Name = L"series_axis_x";
				this->chart2->Series->Add(series2);
				this->chart2->Size = System::Drawing::Size(800, 100);
				this->chart2->TabIndex = 1;
				this->chart2->Text = L"chart2";
				// 
				// chart3
				// 
				chartArea3->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
				chartArea3->AxisX->Maximum = 400;
				chartArea3->AxisX->Minimum = 0;
				chartArea3->AxisX->ToolTip = L"Sample Number";
				chartArea3->AxisY->Title = L"TBD";
				chartArea3->Name = L"ChartArea1";
				this->chart3->ChartAreas->Add(chartArea3);
				legend3->Name = L"Legend1";
				legend3->Title = L"Sensor3";
				this->chart3->Legends->Add(legend3);
				this->chart3->Location = System::Drawing::Point(340, 226);
				this->chart3->Name = L"chart3";
				series3->ChartArea = L"ChartArea1";
				series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				series3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				series3->Legend = L"Legend1";
				series3->LegendText = L"Data";
				series3->Name = L"datas";
				this->chart3->Series->Add(series3);
				this->chart3->Size = System::Drawing::Size(800, 100);
				this->chart3->TabIndex = 2;
				this->chart3->Text = L"chart3";
				this->chart3->Click += gcnew System::EventHandler(this, &MyForm::chart3_Click);
				// 
				// chart4
				// 
				chartArea4->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
				chartArea4->AxisX->Maximum = 400;
				chartArea4->AxisX->Minimum = 0;
				chartArea4->Name = L"ChartArea1";
				this->chart4->ChartAreas->Add(chartArea4);
				legend4->Name = L"Legend1";
				legend4->Title = L"Sensor4";
				this->chart4->Legends->Add(legend4);
				this->chart4->Location = System::Drawing::Point(340, 340);
				this->chart4->Name = L"chart4";
				series4->ChartArea = L"ChartArea1";
				series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				series4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				series4->Legend = L"Legend1";
				series4->LegendText = L"Ch1";
				series4->Name = L"Ch1";
				series5->ChartArea = L"ChartArea1";
				series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				series5->Color = System::Drawing::Color::Red;
				series5->Legend = L"Legend1";
				series5->LegendText = L"Ch2";
				series5->Name = L"Ch2";
				series6->ChartArea = L"ChartArea1";
				series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
				series6->Color = System::Drawing::Color::Blue;
				series6->Legend = L"Legend1";
				series6->LegendText = L"Diff";
				series6->Name = L"Differential";
				this->chart4->Series->Add(series4);
				this->chart4->Series->Add(series5);
				this->chart4->Series->Add(series6);
				this->chart4->Size = System::Drawing::Size(800, 100);
				this->chart4->TabIndex = 3;
				this->chart4->Text = L"chart4";
				// 
				// open_log_button
				// 
				this->open_log_button->Location = System::Drawing::Point(10, 340);
				this->open_log_button->Name = L"open_log_button";
				this->open_log_button->Size = System::Drawing::Size(75, 23);
				this->open_log_button->TabIndex = 4;
				this->open_log_button->Text = L"Open Log";
				this->open_log_button->UseVisualStyleBackColor = true;
				this->open_log_button->Click += gcnew System::EventHandler(this, &MyForm::open_log_button_Click);
				// 
				// close_log_button
				// 
				this->close_log_button->Enabled = false;
				this->close_log_button->Location = System::Drawing::Point(91, 340);
				this->close_log_button->Name = L"close_log_button";
				this->close_log_button->Size = System::Drawing::Size(75, 23);
				this->close_log_button->TabIndex = 5;
				this->close_log_button->Text = L"Close Log";
				this->close_log_button->UseVisualStyleBackColor = true;
				this->close_log_button->Click += gcnew System::EventHandler(this, &MyForm::close_log_button_Click);
				// 
				// comboBoxSerialPortName
				// 
				this->comboBoxSerialPortName->FormattingEnabled = true;
				this->comboBoxSerialPortName->Location = System::Drawing::Point(10, 399);
				this->comboBoxSerialPortName->Name = L"comboBoxSerialPortName";
				this->comboBoxSerialPortName->Size = System::Drawing::Size(121, 21);
				this->comboBoxSerialPortName->TabIndex = 6;
				this->comboBoxSerialPortName->DropDown += gcnew System::EventHandler(this, &MyForm::comboBox1_DropDown);
				// 
				// openPortButton
				// 
				this->openPortButton->Location = System::Drawing::Point(137, 397);
				this->openPortButton->Name = L"openPortButton";
				this->openPortButton->Size = System::Drawing::Size(75, 23);
				this->openPortButton->TabIndex = 7;
				this->openPortButton->Text = L"Open Port";
				this->openPortButton->UseVisualStyleBackColor = true;
				this->openPortButton->Click += gcnew System::EventHandler(this, &MyForm::openPortButton_Click);
				// 
				// input_port
				// 
				this->input_port->BaudRate = 115200;
				this->input_port->ReadBufferSize = 256;
				this->input_port->ReadTimeout = 100;
				this->input_port->WriteTimeout = 500;
				this->input_port->ErrorReceived += gcnew System::IO::Ports::SerialErrorReceivedEventHandler(this, &MyForm::input_port_error_handler);
				this->input_port->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::input_port_data_handler);
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1152, 452);
				this->Controls->Add(this->openPortButton);
				this->Controls->Add(this->comboBoxSerialPortName);
				this->Controls->Add(this->close_log_button);
				this->Controls->Add(this->open_log_button);
				this->Controls->Add(this->chart4);
				this->Controls->Add(this->chart3);
				this->Controls->Add(this->chart2);
				this->Controls->Add(this->chart1);
				this->MaximizeBox = false;
				this->MaximumSize = System::Drawing::Size(1168, 491);
				this->MinimizeBox = false;
				this->MinimumSize = System::Drawing::Size(1168, 491);
				this->Name = L"MyForm";
				this->ShowIcon = false;
				this->Text = L"DataDisplay";
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->EndInit();
				this->ResumeLayout(false);

			}
#pragma endregion
    private:
		System::Void timer1_Tick(System::Object^  sender,
			System::EventArgs^  e)
		{
			array<uint8_t>^ new_data;
			UNREFERENCED_PARAMETER(sender);
			UNREFERENCED_PARAMETER(e);
			Monitor::Enter(input_queue);
			try {
				while (input_queue->Count > 0) {
					new_data = input_queue->Dequeue();
					process_input(new_data);
				}
			} catch (Exception^ e) {
			} finally {
				Monitor::Exit(input_queue);
			}
		}
		System::Void AddNewData(float *processed_data, int num_processed, float *metrics, int num_misc)
		{
			int ii;
                if (chart1->Series[0]->Points->Count == chart2->ChartAreas[0]->Axes[0]->Maximum) {
					chart1->Series[0]->Points->SuspendUpdates();
                    chart1->Series[0]->Points->RemoveAt(0);
					chart1->Series[0]->Points->ResumeUpdates();
                }

                if (chart2->Series[0]->Points->Count == chart2->ChartAreas[0]->Axes[0]->Maximum) {
					chart2->Series[0]->Points->SuspendUpdates();
                    chart2->Series[0]->Points->RemoveAt(0);
					chart2->Series[0]->Points->ResumeUpdates();
                }

                if (chart3->Series[0]->Points->Count == chart3->ChartAreas[0]->Axes[0]->Maximum) {
					chart3->Series[0]->Points->SuspendUpdates();
                    chart3->Series[0]->Points->RemoveAt(0);
					chart3->Series[0]->Points->ResumeUpdates();
                }
				if (chart4->Series[0]->Points->Count == chart4->ChartAreas[0]->Axes[0]->Maximum) {
					chart4->Series[0]->Points->SuspendUpdates();
					chart4->Series[0]->Points->RemoveAt(0);
					chart4->Series[0]->Points->ResumeUpdates();
				}
		
				chart1->Series[0]->Points->Add(processed_data[0]);
				chart2->Series[0]->Points->Add(processed_data[1]);
				chart3->Series[0]->Points->Add(processed_data[2]);
				chart4->Series[0]->Points->Add(processed_data[3]);
				//chart4->Series[1]->Points->Add(processed_data[2]);
				//chart4->Series[2]->Points->Add(processed_data[3]);
				chart1->ChartAreas[0]->RecalculateAxesScale();
				chart2->ChartAreas[0]->RecalculateAxesScale();
				chart3->ChartAreas[0]->RecalculateAxesScale();
				chart4->ChartAreas[0]->RecalculateAxesScale();
#if 0
				if (chart1->ChartAreas[0]->AxisY->Maximum < 1)
					chart1->ChartAreas[0]->AxisY->Maximum = 1;
				if (chart1->ChartAreas[0]->AxisY->Minimum > -1)
					chart1->ChartAreas[0]->AxisY->Maximum = -1;

				if (chart2->ChartAreas[0]->AxisY->Maximum < 10)
					chart2->ChartAreas[0]->AxisY->Maximum = 10;
				if (chart2->ChartAreas[0]->AxisY->Minimum > -10)
					chart2->ChartAreas[0]->AxisY->Maximum = -10;

				if (chart3->ChartAreas[0]->AxisY->Maximum < 50)
					chart3->ChartAreas[0]->AxisY->Maximum = 50;
				if (chart3->ChartAreas[0]->AxisY->Minimum > -50)
					chart3->ChartAreas[0]->AxisY->Maximum = -50;
#endif
				if (logWriter != nullptr) {
					System::String^ misc_string = gcnew System::String(L"");
					for (ii = 0; ii < num_processed; ii++) {
						misc_string += L", ";
						misc_string += processed_data[ii].ToString();
					}
					for (ii = 0; ii < num_misc; ii++) {
						misc_string += L", ";
						misc_string += metrics[ii].ToString();
					}
					logWriter->WriteLine(misc_string);
				}
			}
	private: System::Void open_log_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->Filter = "csv files (*.csv)|*.csv|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 1;
		openFileDialog1->RestoreDirectory = true;
		openFileDialog1->CheckFileExists = false;
		openFileDialog1->ReadOnlyChecked = false;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((logFileStream = gcnew FileStream(openFileDialog1->FileName, FileMode::Create, FileAccess::Write)) != nullptr)
			{
				logWriter = gcnew StreamWriter(logFileStream);
				this->open_log_button->Enabled = false;
				this->close_log_button->Enabled = true;
			}
		}
	}
private:
	System::Void close_log_button_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->open_log_button->Enabled = true;
		this->close_log_button->Enabled = false;
		logWriter->Close();
		delete logWriter;
		logWriter = nullptr;
		logFileStream->Close();
		delete logFileStream;
		logFileStream = nullptr;
	}
	System::Void populatePortList()
	{
		array<Object^>^ ports = SerialPort::GetPortNames();
		if (ports->Length > 0) {
			comboBoxSerialPortName->Items->Clear();
			comboBoxSerialPortName->Items->AddRange(ports);
			comboBoxSerialPortName->SelectedIndex = 0;
		}
	}
	System::Void openPortButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		/* memory failure */
		if (input_port == nullptr)
			return;

		if(!input_port->IsOpen) {
			input_port->PortName = comboBoxSerialPortName->Text;
			input_port->BaudRate = 115200;
			input_port->Open();
			if (input_port->IsOpen) {
				input_port->DtrEnable = true;
				openPortButton->Text = L"Close Port";
			}
		} else {
			try {
				if (input_port->IsOpen)
					input_port->Close();
			} finally {
				openPortButton->Text = L"Open Port";
			}
		}
	}

	System::Void comboBox1_DropDown(System::Object^  sender, System::EventArgs^  e)
	{
		populatePortList();
	}
	System::Void input_port_error_handler(System::Object^ sender, System::IO::Ports::SerialErrorReceivedEventArgs^ e)
	{

	}
	private:
		System::Void input_port_data_handler(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e)
		{
			int ii=0, chars_read = input_port->BytesToRead;
			if (!chars_read)
				return;

			array<uint8_t>^ buffer = gcnew array<uint8_t>(chars_read);

			try {
				chars_read = input_port->Read(buffer, 0, chars_read);
			}
			catch (Exception^ err) {
				if (err) {
					// Do something useful
				}
				else {
					// Do something useful
				}
				chars_read = 0;
				return;
			}

			if (chars_read > 5) {

				for (ii = 0; ii < chars_read; ii++) {
					if (buffer[ii] == '[' && packet_len == 0) {
						if (input_array == nullptr) {
							input_array = gcnew array<uint8_t>(256);
						}
						else {
							packet_len = packet_len; //Dummy, used for breakpt.
						}
						input_array[packet_len] = buffer[ii];
						packet_len++;
					}
					else if ((packet_len > 0) && (input_array != nullptr)) { //sizeof(struct gui_measurement_data)
						input_array[packet_len] = buffer[ii];
						if (packet_len > 12) {
							if (buffer[ii] == ']' &&  buffer[ii - 1] == ',') { //packet_len == sizeof(struct gui_measurement_data) && buffer[ii] == ']' 
								packet_len++;  //required to keep the alignment
								Monitor::Enter(input_queue);
								try {
									input_queue->Enqueue(input_array);
									packet_len = 0;
									input_array = nullptr;
								}
								finally {
									Monitor::Exit(input_queue);
								}
							}
							else {
								packet_len++;
							}
						}
						else {
							packet_len++;
						}
						if (packet_len > 40) {
							input_array = nullptr;
							packet_len = 0;
						}
					}
				}
			}
			}
	void process_input(array<uint8_t>^ measurement_bytes) {
		float processed_data[4 + 6 * 3];
		float other_metrics[4];// placeholder
		float tempvar = 0.0;
		int ii, kk;
		kk = 0;

		array<wchar_t>^ delimiter = {',', '\n', '\r'};
		array<String ^>^ element_split;
		String^	sa = System::Text::Encoding::Default->GetString(measurement_bytes);
		element_split = sa->Split(delimiter);

		for (ii = 1; ii < NUM_DATA_SOURCES+1; ii++){  //the +1 is because the index is starting from 1 instead of 0
			tempvar = Convert::ToDouble(element_split[ii]);
			if (tempvar <2048.0 && tempvar > -2048.0) {
				processed_data[kk] = tempvar;
			}
			else {
				processed_data[kk] = 0.0;
			}

			kk++;
		}

		kk = 0;
		for (ii = 0; ii < 4; ii++) {  //Placeholder for other data sources
			other_metrics[kk] = rand();
			kk++;
		}
		AddNewData(processed_data, 22, other_metrics, 4);
	}
private: System::Void chart3_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
