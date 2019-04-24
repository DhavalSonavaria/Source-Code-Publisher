using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using Path = System.IO.Path;


namespace CodePub_GUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Translator shim;
        private string wDirectory { get; set; }
        private string Patterns { get; set; }
        private string Regex { get; set; }
        private List<string> args { get; set; }
        private List<string> conFiles { get; set; }
        public MainWindow()
        {
            InitializeComponent();
             List<String> args = new List<string>();
        }

        private void BtnBrowse_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Forms.FolderBrowserDialog dialog;
            dialog = new System.Windows.Forms.FolderBrowserDialog();
            if(dialog.ShowDialog()==System.Windows.Forms.DialogResult.OK)
            {
                wDirectory = dialog.SelectedPath;
                txtPath.Text = wDirectory;
            }
        }

        private void BtnPublish_Click(object sender, RoutedEventArgs e)
        {
            lstConverted.Items.Clear();
            shim = new Translator();
            shim.Start();
            sendArgs();
            display();
            Tabctrl.SelectedIndex = 1;
            
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            List<String> conFiles = new List<string>();
            List<String> args = new List<string>();
            string dir = txtPath.Text;
            dir = Path.GetFullPath(dir);
            wDirectory = dir;
            Regex = txtRegex.ToString();
            Patterns = txtPatterns.ToString();
            shim = new Translator();
            shim.Start();
            args.Add("prog.exe");
            if(wDirectory!=null)
                args.Add(wDirectory);
            if (cbRecurse.IsChecked.HasValue) args.Add("/s");
            if(Regex!=null)
                args.AddRange(Regex.Split(' '));
            if(Patterns!=null)
                args.AddRange(Patterns.Split(' '));
            shim.SendCmd(args);
            conFiles = shim.returnFile();
            if (conFiles.Count() == 0) { lstConverted.Items.Insert(0, "No files found"); }
            else
            {
                for (int i = 0; i < conFiles.Count; i++)
                    lstConverted.Items.Insert(i, Path.GetFileNameWithoutExtension(conFiles[i]));
            }
            
            Tabctrl.SelectedIndex = 1;
        }
        private void display()
        {
            List<String> conFiles = new List<string>();
            conFiles = shim.returnFile();
            if (conFiles.Count() == 0) { lstConverted.Items.Insert(0, "No files found"); }
            else
            {
                for (int i = 0; i < conFiles.Count; i++)
                    lstConverted.Items.Insert(i, Path.GetFileNameWithoutExtension(conFiles[i]));
            }
            Tabctrl.SelectedIndex = 1;
        }
        

        private void TxtPath_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (lstFiles != null)
            {
                lstFiles.Items.Clear();
                lstFiles.Items.Add("[..]");
                var dirs = Directory.GetDirectories(wDirectory);
                foreach (var dir in dirs)
                {
                    string dirName = "{" + Path.GetFileName(dir) + "}";
                    lstFiles.Items.Add(Path.GetFileName(dirName));
                }
                List<string> filesMatchingPattern = new List<string>();
                if (Patterns != null&& filesMatchingPattern.Count()!=0)
                {
                    var patterns = Patterns.Split(' ');
                    foreach (var patt in patterns)
                        filesMatchingPattern.AddRange(Directory.GetFiles(wDirectory, patt));
                }
                else
                {
                    filesMatchingPattern = Directory.GetFiles(wDirectory).ToList();
                }
                foreach (var file in filesMatchingPattern) lstFiles.Items.Add(Path.GetFileName(file));
            }
        }
        private void LstFiles_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            if (lstFiles.SelectedIndex == -1) return;

            string selectedItem = lstFiles.SelectedItem.ToString();
            selectedItem = selectedItem.Substring(1, selectedItem.Length - 2);
            selectedItem = Path.Combine(wDirectory, selectedItem);
            selectedItem = Path.GetFullPath(selectedItem);
            if (!Directory.Exists(selectedItem)) return;
            wDirectory = selectedItem;
            txtPath.Text = selectedItem;
        }
        void clearArgs()
        {
            args.Clear();
        }
        void sendArgs()
        {
            
            Regex = txtRegex.Text;
            Patterns = txtPatterns.Text;
            List<String> args = new List<string>();
            args.Add("prog.exe");
            if (wDirectory != null)
                args.Add(wDirectory);
            if (cbRecurse.IsChecked.HasValue) args.Add("/s");
            if (Regex != null)
                args.AddRange(Regex.Split(' '));
            if (Patterns != null)
                args.AddRange(Patterns.Split(' ')); 
             shim.SendCmd(args);
            args.Clear();
        }

        private void LstConverted_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            string path = "..\\ConvertedWebpages\\";
            string process = path + lstConverted.SelectedItem.ToString() + ".html";
            string complete = Path.GetFullPath(process);
            System.Diagnostics.Process.Start(process);
        }
    }
}