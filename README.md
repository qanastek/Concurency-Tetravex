<p align="center">
  <img src="https://github.com/qanastek/Concurency-Tetravex/blob/master/ressources/images/logo.png" width="40%">
</p>

This software is an fast and reliable tetravex solver based on C++ and CUDA.

## Dependencies

- [CUDA](https://developer.nvidia.com/cuda-downloads)

## Run the project

- Start the project
  - `make para`

## Speeds

|  Method  |    5x5   |    6x6   |    7x7    |     8x8    |
|:--------:|:--------:|:--------:|:---------:|:----------:|
|    Seq   |  3,838s  |  4,207s  | 0m20.116s |  7m38.411s |
| Parallal | 0m5.633s | 0m6.214s | 0m38.047s |   No RAM   |
|   Pool   | 0m7.624s | 0m8.736s | 0m28.154s |   No RAM   |

## Architecture

<p align="center">
  <img src="https://github.com/qanastek/Concurency-Tetravex/blob/master/modelisation/Render/Overview.png" width="80%">
</p>
