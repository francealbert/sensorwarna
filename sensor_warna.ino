// Definisikan pin untuk sensor TCS3200
const int S0 = 4;
const int S1 = 5;
const int S2 = 6;
const int S3 = 7;
const int sensorOut = 8;

// Variabel untuk menyimpan hasil pembacaan sensor
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {
  // Set pin sebagai output
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Konfigurasi sensor untuk pengukuran skala penuh
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  // Mengukur frekuensi warna merah
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);

  // Mengukur frekuensi warna hijau
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);

  // Mengukur frekuensi warna biru
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  // Menampilkan hasil pengukuran
  Serial.print("Red: ");
  Serial.print(redFrequency);
  Serial.print(" - Green: ");
  Serial.print(greenFrequency);
  Serial.print(" - Blue: ");
  Serial.println(blueFrequency);

  // Memberi jeda sebelum pengukuran berikutnya
  delay(1000);
}