#pragma once
#include "MarkovAlgorithm.h"
#include <algorithm> // Для использования std::remove.

namespace НормальныеалгоритмыМаркова {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;using namespace System::IO;
using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  AlgorithmSteps;
	private: System::Windows::Forms::TextBox^  SourceWord;
	private: System::Windows::Forms::Button^  Solve;
	private: System::Windows::Forms::Button^  LoadFromFile;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Label^  TSourceWord;
	private: System::Windows::Forms::Button^  Add;
	private: System::Windows::Forms::TextBox^  SymbBefore;
	private: System::Windows::Forms::TextBox^  SymbAfter;
	private: System::Windows::Forms::Label^  TArrow;
	private: System::Windows::Forms::DataGridView^  Substitutions;
	private: System::Windows::Forms::Button^  TableDel;
	private: System::Windows::Forms::Button^  TableUp;
	private: System::Windows::Forms::Button^  TableDown;
	private: System::Windows::Forms::Button^  Clear;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  SubstSymbols;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Substution;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->AlgorithmSteps = (gcnew System::Windows::Forms::TextBox());
			this->SourceWord = (gcnew System::Windows::Forms::TextBox());
			this->Solve = (gcnew System::Windows::Forms::Button());
			this->LoadFromFile = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->TSourceWord = (gcnew System::Windows::Forms::Label());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->SymbBefore = (gcnew System::Windows::Forms::TextBox());
			this->SymbAfter = (gcnew System::Windows::Forms::TextBox());
			this->TArrow = (gcnew System::Windows::Forms::Label());
			this->Substitutions = (gcnew System::Windows::Forms::DataGridView());
			this->TableDel = (gcnew System::Windows::Forms::Button());
			this->TableUp = (gcnew System::Windows::Forms::Button());
			this->TableDown = (gcnew System::Windows::Forms::Button());
			this->Clear = (gcnew System::Windows::Forms::Button());
			this->SubstSymbols = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Substution = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Substitutions))->BeginInit();
			this->SuspendLayout();
			// 
			// AlgorithmSteps
			// 
			this->AlgorithmSteps->BackColor = System::Drawing::SystemColors::Window;
			this->AlgorithmSteps->Location = System::Drawing::Point(420, 12);
			this->AlgorithmSteps->Multiline = true;
			this->AlgorithmSteps->Name = L"AlgorithmSteps";
			this->AlgorithmSteps->ReadOnly = true;
			this->AlgorithmSteps->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->AlgorithmSteps->Size = System::Drawing::Size(237, 347);
			this->AlgorithmSteps->TabIndex = 10;
			this->AlgorithmSteps->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->AlgorithmSteps->WordWrap = false;
			// 
			// SourceWord
			// 
			this->SourceWord->Enabled = false;
			this->SourceWord->Font = (gcnew System::Drawing::Font(L"Century", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SourceWord->Location = System::Drawing::Point(69, 329);
			this->SourceWord->MinimumSize = System::Drawing::Size(106, 29);
			this->SourceWord->Name = L"SourceWord";
			this->SourceWord->Size = System::Drawing::Size(135, 26);
			this->SourceWord->TabIndex = 5;
			// 
			// Solve
			// 
			this->Solve->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Solve->Enabled = false;
			this->Solve->Location = System::Drawing::Point(210, 326);
			this->Solve->Name = L"Solve";
			this->Solve->Size = System::Drawing::Size(150, 30);
			this->Solve->TabIndex = 6;
			this->Solve->Text = L"Решить";
			this->Solve->UseVisualStyleBackColor = true;
			this->Solve->Click += gcnew System::EventHandler(this, &MyForm::Solve_Click);
			// 
			// LoadFromFile
			// 
			this->LoadFromFile->Cursor = System::Windows::Forms::Cursors::Hand;
			this->LoadFromFile->Location = System::Drawing::Point(12, 290);
			this->LoadFromFile->Name = L"LoadFromFile";
			this->LoadFromFile->Size = System::Drawing::Size(171, 26);
			this->LoadFromFile->TabIndex = 3;
			this->LoadFromFile->Text = L"Загрузить из файла";
			this->LoadFromFile->UseVisualStyleBackColor = true;
			this->LoadFromFile->Click += gcnew System::EventHandler(this, &MyForm::LoadFromFile_Click);
			// 
			// TSourceWord
			// 
			this->TSourceWord->AutoSize = true;
			this->TSourceWord->Location = System::Drawing::Point(9, 335);
			this->TSourceWord->Name = L"TSourceWord";
			this->TSourceWord->Size = System::Drawing::Size(56, 18);
			this->TSourceWord->TabIndex = 4;
			this->TSourceWord->Text = L"Слово:";
			// 
			// Add
			// 
			this->Add->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Add->Location = System::Drawing::Point(243, 255);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(117, 27);
			this->Add->TabIndex = 2;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &MyForm::Add_Click);
			// 
			// SymbBefore
			// 
			this->SymbBefore->Location = System::Drawing::Point(12, 255);
			this->SymbBefore->Name = L"SymbBefore";
			this->SymbBefore->Size = System::Drawing::Size(87, 26);
			this->SymbBefore->TabIndex = 0;
			// 
			// SymbAfter
			// 
			this->SymbAfter->Location = System::Drawing::Point(135, 255);
			this->SymbAfter->Name = L"SymbAfter";
			this->SymbAfter->Size = System::Drawing::Size(91, 26);
			this->SymbAfter->TabIndex = 1;
			// 
			// TArrow
			// 
			this->TArrow->AutoSize = true;
			this->TArrow->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TArrow->Location = System::Drawing::Point(105, 259);
			this->TArrow->Name = L"TArrow";
			this->TArrow->Size = System::Drawing::Size(24, 18);
			this->TArrow->TabIndex = 8;
			this->TArrow->Text = L"->";
			// 
			// Substitutions
			// 
			this->Substitutions->AllowUserToAddRows = false;
			this->Substitutions->AllowUserToDeleteRows = false;
			this->Substitutions->AllowUserToResizeColumns = false;
			this->Substitutions->AllowUserToResizeRows = false;
			this->Substitutions->BackgroundColor = System::Drawing::SystemColors::Window;
			this->Substitutions->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Century", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->Substitutions->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->Substitutions->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Substitutions->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->SubstSymbols,
					this->Substution
			});
			this->Substitutions->Location = System::Drawing::Point(12, 12);
			this->Substitutions->MultiSelect = false;
			this->Substitutions->Name = L"Substitutions";
			this->Substitutions->ReadOnly = true;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Century", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->Substitutions->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->Substitutions->RowHeadersWidth = 50;
			this->Substitutions->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->Substitutions->Size = System::Drawing::Size(348, 233);
			this->Substitutions->TabIndex = 11;
			this->Substitutions->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MyForm::Substitutions_RowsAdded);
			this->Substitutions->SelectionChanged += gcnew System::EventHandler(this, &MyForm::Substitutions_SelectionChanged);
			// 
			// TableDel
			// 
			this->TableDel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->TableDel->Enabled = false;
			this->TableDel->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->TableDel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TableDel.Image")));
			this->TableDel->Location = System::Drawing::Point(375, 38);
			this->TableDel->Name = L"TableDel";
			this->TableDel->Size = System::Drawing::Size(29, 30);
			this->TableDel->TabIndex = 7;
			this->TableDel->UseVisualStyleBackColor = true;
			this->TableDel->Click += gcnew System::EventHandler(this, &MyForm::TableDel_Click);
			// 
			// TableUp
			// 
			this->TableUp->Cursor = System::Windows::Forms::Cursors::Hand;
			this->TableUp->Enabled = false;
			this->TableUp->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->TableUp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TableUp.Image")));
			this->TableUp->Location = System::Drawing::Point(375, 74);
			this->TableUp->Name = L"TableUp";
			this->TableUp->Size = System::Drawing::Size(29, 30);
			this->TableUp->TabIndex = 8;
			this->TableUp->UseVisualStyleBackColor = true;
			this->TableUp->Click += gcnew System::EventHandler(this, &MyForm::TableUp_Click);
			// 
			// TableDown
			// 
			this->TableDown->Cursor = System::Windows::Forms::Cursors::Hand;
			this->TableDown->Enabled = false;
			this->TableDown->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->TableDown->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TableDown.Image")));
			this->TableDown->Location = System::Drawing::Point(375, 110);
			this->TableDown->Name = L"TableDown";
			this->TableDown->Size = System::Drawing::Size(29, 29);
			this->TableDown->TabIndex = 9;
			this->TableDown->UseVisualStyleBackColor = true;
			this->TableDown->Click += gcnew System::EventHandler(this, &MyForm::TableDown_Click);
			// 
			// Clear
			// 
			this->Clear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Clear->Enabled = false;
			this->Clear->Location = System::Drawing::Point(189, 290);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(171, 26);
			this->Clear->TabIndex = 4;
			this->Clear->Text = L"Очистить";
			this->Clear->UseVisualStyleBackColor = true;
			this->Clear->Click += gcnew System::EventHandler(this, &MyForm::Clear_Click);
			// 
			// SubstSymbols
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->SubstSymbols->DefaultCellStyle = dataGridViewCellStyle2;
			this->SubstSymbols->HeaderText = L"Символы замены";
			this->SubstSymbols->Name = L"SubstSymbols";
			this->SubstSymbols->ReadOnly = true;
			this->SubstSymbols->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->SubstSymbols->Width = 138;
			// 
			// Substution
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->Substution->DefaultCellStyle = dataGridViewCellStyle3;
			this->Substution->HeaderText = L"Подстановка";
			this->Substution->Name = L"Substution";
			this->Substution->ReadOnly = true;
			this->Substution->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Substution->Width = 138;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(669, 371);
			this->Controls->Add(this->Clear);
			this->Controls->Add(this->TableDown);
			this->Controls->Add(this->TableUp);
			this->Controls->Add(this->TableDel);
			this->Controls->Add(this->Substitutions);
			this->Controls->Add(this->LoadFromFile);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->TArrow);
			this->Controls->Add(this->SymbAfter);
			this->Controls->Add(this->TSourceWord);
			this->Controls->Add(this->SymbBefore);
			this->Controls->Add(this->Solve);
			this->Controls->Add(this->SourceWord);
			this->Controls->Add(this->AlgorithmSteps);
			this->Font = (gcnew System::Drawing::Font(L"Century", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Нормальные алгоритмы Маркова";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Substitutions))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool Replacement(std::string &word, bool *replaceOfEmptiness) {
			for (unsigned int i = 0; i < MarkovAlgorithm::symbols.size(); i++) {
				// Находим позицию заменяемых символов.
				int pos = word.find(MarkovAlgorithm::symbols[i]);

				if (pos != std::string::npos) { // Проверяем, есть ли в строке символы, подлежащие замене.
					word.replace(pos, MarkovAlgorithm::symbols[i].length(), MarkovAlgorithm::substitutions[i]);

					// Проверяем, не заменяется ли пустота два раза подряд.	
					if (MarkovAlgorithm::symbols[i].length() == 0) {
						if (*replaceOfEmptiness == true)
							return true;
						*replaceOfEmptiness = true;
					}
					else *replaceOfEmptiness = false;

					// Проверяем, является ли текущая подстановка заключительной.
					if (word.find('.') != std::string::npos) {
						word.erase(remove(word.begin(), word.end(), '.'), word.end());
						return true;
					}
					else return false;
				}
			}
			return true;
		}

		private: System::Void Solve_Click(System::Object^  sender, System::EventArgs^  e) {
			std::vector<std::string> steps; // Вектор с состояниями входного слова на каждом шаге.

			// Проверяем, не изменились ли значения подстановок в таблице.
			// Если изменения произошли, обновляем значения в векторе. 
			for (int i = 0; i < Substitutions->RowCount; i++){
				std::string expression = static_cast<char*>((Marshal::StringToHGlobalAnsi(Substitutions->Rows[i]->Cells[0]->Value->ToString())).ToPointer());
				if (expression != MarkovAlgorithm::symbols[i])
					MarkovAlgorithm::symbols[i] = expression;
				expression = static_cast<char*>((Marshal::StringToHGlobalAnsi(Substitutions->Rows[i]->Cells[1]->Value->ToString())).ToPointer());
				if (expression != MarkovAlgorithm::substitutions[i])
					MarkovAlgorithm::substitutions[i] = expression;
			}
			std::string sourceWord = static_cast<char*>((Marshal::StringToHGlobalAnsi(SourceWord->Text)).ToPointer());
			AlgorithmSteps->Text = "_" + SourceWord->Text + "_" + Environment::NewLine;

			bool finalSubstitution = false; // Заключительная подстановка.
			bool replacementOfEmptiness = false; // Переменная, показывающая, что в предыдущем шаге заменялась пустота.
			while (!finalSubstitution) {
				steps.push_back(sourceWord); // Добавляем слово в вектор состояний слова.
				
				finalSubstitution = Replacement(sourceWord, &replacementOfEmptiness);
				// Выводим слово после подстановки в таблицу шагов алгоритма.
				AlgorithmSteps->Text += "_" + gcnew String(sourceWord.c_str()) + "_" + Environment::NewLine;

				if(finalSubstitution && replacementOfEmptiness)
					MessageBox::Show("В алгоритме присутствует ошибка!\nДальнейшее продолжение приведёт к зацикливанию алгоритма!", "", MessageBoxButtons::OK, MessageBoxIcon::Warning);

				// Проверяем, было ли текущее состояние слова в предыдущих шагах подстановок.
				for (int i = 0; i < steps.size() && !finalSubstitution; i++){
					if (sourceWord == steps[i]) {
						MessageBox::Show("В алгоритме присутствует ошибка!\nДальнейшее продолжение приведёт к зацикливанию алгоритма!", "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						finalSubstitution = true;
					}
				}
			}
		}
	private: System::Void LoadFromFile_Click(System::Object^  sender, System::EventArgs^  e) {
		Stream^ myStream;
		openFileDialog->InitialDirectory = Application::StartupPath;
		openFileDialog->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog->FilterIndex = 2;

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((myStream = openFileDialog->OpenFile()) != nullptr) {
				char* name = static_cast<char*>(Marshal::StringToHGlobalAnsi(openFileDialog->FileName).ToPointer());
				
				// Очищаем таблицу и векторы подстановок.
				if (!MarkovAlgorithm::symbols.empty()) MarkovAlgorithm::symbols.clear();
				if (!MarkovAlgorithm::substitutions.empty()) MarkovAlgorithm::substitutions.clear();
				Substitutions->Rows->Clear();

				switch (MarkovAlgorithm::SetArraysOfSubstitutions(name)) {
				case 0:
					for (unsigned int i = 0; i < MarkovAlgorithm::symbols.size(); i++) {
						Substitutions->Rows->Add();
						Substitutions->Rows[i]->Cells[0]->Value = gcnew String(MarkovAlgorithm::symbols[i].c_str());
						Substitutions->Rows[i]->Cells[1]->Value = gcnew String(MarkovAlgorithm::substitutions[i].c_str());
					}

					SourceWord->Enabled = true;
					Solve->Enabled = true;
					Clear->Enabled = true;
					TableUp->Enabled = false;
					TableDel->Enabled = true;
					if (Substitutions->RowCount > 1) TableDown->Enabled = true;
					break;
				case 1: MessageBox::Show("Файл повреждён!"); break;
				case -1: MessageBox::Show("Неверный формат данных в файле!\n" + 
					"Каждая подстановка должна начинаться с новой строки,\n" +
					"между собой заменяемый и подставляемый текст отделяются\n" +
					"такой последовательностью символов: \"->\".", "", MessageBoxButtons::OK, MessageBoxIcon::Stop);
					break;
				}
				myStream->Close();
			}
		}
	}
	private: System::Void Substitutions_RowsAdded(System::Object^  sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^  e) {
		// Выводим порядковый номер добавляемой строки.	
		Substitutions->Rows[Substitutions->RowCount - 1]->HeaderCell->Value = Convert::ToString(Substitutions->RowCount);
	}
private: System::Void Add_Click(System::Object^  sender, System::EventArgs^  e) {
	if (SymbAfter->Text != "") {
		// Добавляем строку в таблицу.
		Substitutions->RowCount += 1;

		// Активируем кнопки.
		if (SourceWord->Enabled == false) SourceWord->Enabled = true;
		if (Solve->Enabled == false) Solve->Enabled = true;
		if (TableDel->Enabled == false) TableDel->Enabled = true;
		if (Clear->Enabled == false) Clear->Enabled = true;
		if(Substitutions->RowCount > 1 && TableDown->Enabled == false) TableDown->Enabled = true;

		// Добавляем значения в векторы подстановок.
		char* before = static_cast<char*>(Marshal::StringToHGlobalAnsi(SymbBefore->Text).ToPointer());
		char* after = static_cast<char*>(Marshal::StringToHGlobalAnsi(SymbAfter->Text).ToPointer());
		MarkovAlgorithm::symbols.push_back(before);
		MarkovAlgorithm::substitutions.push_back(after);

		// Добавляем значения в таблицу подстановок.
		Substitutions->Rows[Substitutions->RowCount - 1]->Cells[0]->Value = SymbBefore->Text;
		Substitutions->Rows[Substitutions->RowCount - 1]->Cells[1]->Value = SymbAfter->Text;
	}
}
private: System::Void TableDel_Click(System::Object^  sender, System::EventArgs^  e) {
	MarkovAlgorithm::symbols.erase(MarkovAlgorithm::symbols.begin() + Substitutions->CurrentCell->RowIndex);
	MarkovAlgorithm::substitutions.erase(MarkovAlgorithm::substitutions.begin() + Substitutions->CurrentCell->RowIndex);
	Substitutions->Rows->RemoveAt(Substitutions->CurrentCell->RowIndex);

	// В зависимости от индекса текущий строки ограничиваем доступ к управляющим кнопкам таблицы.
	if (Substitutions->RowCount > 0) {
		if (Substitutions->CurrentCell->RowIndex == 0) TableUp->Enabled = false;
		if (Substitutions->CurrentCell->RowIndex == Substitutions->RowCount - 1) TableDown->Enabled = false;

		for (int i = 0; i < Substitutions->RowCount; i++)
			Substitutions->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
	}
	else {
		TableDel->Enabled = false;
		SourceWord->Enabled = false;
		Solve->Enabled = false;
		Clear->Enabled = false;
	}
}
private: System::Void Clear_Click(System::Object^  sender, System::EventArgs^  e) {
	// Очищаем таблицу и векторы подстановок.
	Substitutions->Rows->Clear();
	MarkovAlgorithm::symbols.clear();
	MarkovAlgorithm::substitutions.clear();

	// Ограничиваем доступ к кнопкам.
	SourceWord->Enabled = false;
	Solve->Enabled = false;
	TableUp->Enabled = false;
	TableDown->Enabled = false;
	TableDel->Enabled = false;
	Clear->Enabled = false;
}
private: System::Void TableUp_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Substitutions->CurrentCell->RowIndex != 0) {
		int currRowIndex = Substitutions->CurrentCell->RowIndex; // Индекс строки текущей ячейки.

		// В зависимости от индекса текущей строки активируем или деактивируем кнопки "Вверх" и "Вниз".
		if (currRowIndex == 1) TableUp->Enabled = false;
		if(currRowIndex == Substitutions->RowCount - 1) TableDown->Enabled = true;

		// Обмен значений в векторе.
		std::string symbsBefore = MarkovAlgorithm::symbols[currRowIndex];
		std::string symbsAfter = MarkovAlgorithm::substitutions[currRowIndex];
		MarkovAlgorithm::symbols[currRowIndex] = MarkovAlgorithm::symbols[currRowIndex - 1];
		MarkovAlgorithm::substitutions[currRowIndex] = MarkovAlgorithm::substitutions[currRowIndex - 1];
		MarkovAlgorithm::symbols[currRowIndex - 1] = symbsBefore;
		MarkovAlgorithm::substitutions[currRowIndex - 1] = symbsAfter;

		// Обмен записей строк в таблице подстановок.
		Substitutions->Rows[currRowIndex - 1]->Cells[0]->Value = gcnew String(MarkovAlgorithm::symbols[currRowIndex - 1].c_str());
		Substitutions->Rows[currRowIndex - 1]->Cells[1]->Value = gcnew String(MarkovAlgorithm::substitutions[currRowIndex - 1].c_str());
		Substitutions->Rows[currRowIndex]->Cells[0]->Value = gcnew String(MarkovAlgorithm::symbols[currRowIndex].c_str());
		Substitutions->Rows[currRowIndex]->Cells[1]->Value = gcnew String(MarkovAlgorithm::substitutions[currRowIndex].c_str());

		// Выделяем ячейку, которая была выделена до поднятия строки вверх в таблице.
		// Теперь она стоит в предыдущей строке.
		Substitutions->CurrentCell = Substitutions[0, currRowIndex - 1];
		SelectCell();
	}
}
private: System::Void TableDown_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Substitutions->CurrentCell->RowIndex != Substitutions->RowCount - 1) {
		int currRowIndex = Substitutions->CurrentCell->RowIndex; // Индекс строки текущей ячейки.

		// В зависимости от индекса текущей строки активируем или деактивируем кнопки "Вверх" и "Вниз".
		if (currRowIndex == 0) TableUp->Enabled = true;
		if (currRowIndex == Substitutions->RowCount - 2) TableDown->Enabled = false;

		// Обмен значений в векторе.
		std::string symbsBefore = MarkovAlgorithm::symbols[currRowIndex];
		std::string symbsAfter = MarkovAlgorithm::substitutions[currRowIndex];
		MarkovAlgorithm::symbols[currRowIndex] = MarkovAlgorithm::symbols[currRowIndex + 1];
		MarkovAlgorithm::substitutions[currRowIndex] = MarkovAlgorithm::substitutions[currRowIndex + 1];
		MarkovAlgorithm::symbols[currRowIndex + 1] = symbsBefore;
		MarkovAlgorithm::substitutions[currRowIndex + 1] = symbsAfter;
		
		// Обмен записей строк в таблице подстановок.
		Substitutions->Rows[currRowIndex]->Cells[0]->Value = gcnew String(MarkovAlgorithm::symbols[currRowIndex].c_str());
		Substitutions->Rows[currRowIndex]->Cells[1]->Value = gcnew String(MarkovAlgorithm::substitutions[currRowIndex].c_str());
		Substitutions->Rows[currRowIndex + 1]->Cells[0]->Value = gcnew String(MarkovAlgorithm::symbols[currRowIndex + 1].c_str());
		Substitutions->Rows[currRowIndex + 1]->Cells[1]->Value = gcnew String(MarkovAlgorithm::substitutions[currRowIndex + 1].c_str());

		// Выделяем ячейку, которая была выделена до смещения строки вниз по таблице.
		// Теперь она стоит в следующей строке.
		Substitutions->CurrentCell = Substitutions[0, currRowIndex + 1];
		SelectCell();
	}
}
void SelectCell() {
	if (Substitutions->RowCount > 2 && Substitutions->CurrentCell->RowIndex > 0
		&& Substitutions->CurrentCell->RowIndex < Substitutions->RowCount - 1) {
		if (TableUp->Enabled == false) TableUp->Enabled = true;
		if (TableDown->Enabled == false) TableDown->Enabled = true;
	}
	else if (Substitutions->RowCount > 1 && Substitutions->CurrentCell->RowIndex == Substitutions->RowCount - 1) {
		if (TableUp->Enabled == false) TableUp->Enabled = true;
		if (TableDown->Enabled == true) TableDown->Enabled = false;
	}
	else if (Substitutions->RowCount > 1 && Substitutions->CurrentCell->RowIndex == 0) {
		if (TableUp->Enabled == true) TableUp->Enabled = false;
		if (TableDown->Enabled == false) TableDown->Enabled = true;
	}
}
private: System::Void Substitutions_SelectionChanged(System::Object^  sender, System::EventArgs^  e) {
	SelectCell();
}
};
}
